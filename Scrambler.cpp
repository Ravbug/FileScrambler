#include "Scrambler.hpp"
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <random>

using namespace std;
using namespace std::filesystem;

void Scrambler::get_paths(vector<path>& torename){
	//shared functionality, called each pass through the iterator
	auto impl = [this,&torename](const path& p){
		if (is_directory(p) || p.filename().string() == ".DS_Store"){
			return;
		}
		{
			bool skip = false;
			//get the name of the file
			auto str = p.filename().string();
			
			//if filename contains skip pattern, continue
			for(const string& pattern : skip_if_contains){
				bool found = str.find(pattern) != std::string::npos;
				
				//handle inversion
				if ((found && !invert_skip) || (!found && invert_skip)){
					skip = true;
					break;
				}
			}
			if (skip){
				return;
			}
		}
		torename.push_back(p);
	};
	
	if (recursive){
		auto iter = recursive_directory_iterator(dir);
		for(const path& p: iter){
			impl(p);
		}
	}
	else{
		auto iter = directory_iterator(dir);
		for(const path& p: iter){
			impl(p);
		}
	}
	
}

path Scrambler::gen_name(const string& id, const std::filesystem::path &p){
	if (penultimate){
		return dir / id;
	}
	else{
		return p.parent_path() / id;
	}
}

path Scrambler::gen_leaf(const path& path){
	if (penultimate){
		return path;
	}
	else{
		return path.filename();
	}
}

path Scrambler::undo_gen_name(const path& p, const std::string& name){
	if (penultimate){
		return name;
	}
	else{
		return p.parent_path() / name;
	}
}

void Scrambler::scramble(){
	int newnum = 0;
	
	vector<string> pathuuid;
	vector<string> names;
	// for each file in directory iterator
	{
		std::vector<path> torename;
		get_paths(torename);

		for(const auto& p : torename){
			//generate id for file
			const string id = to_string(newnum++);
			//update map
			path newpath = gen_name(id, p);
			pathuuid.push_back(newpath);
			names.push_back(gen_leaf(p));
			
			//replace filename with id
			rename(p, newpath);
		}
		
	}
	
	//shuffle values
	std::default_random_engine eng;
	eng.seed(std::chrono::system_clock::now().time_since_epoch().count());
	std::shuffle(names.begin(), names.end(),eng);
	
	//iterate over pathnames in map
	for(int i = 0; i < names.size(); ++i){
		//replace filename with name according to the map
		path uuidpath = pathuuid[i];
		path newpath = undo_gen_name(uuidpath,names[i]);
		try{
			rename(uuidpath,newpath);
		}
		catch(exception& e){
			cerr << e.what() << endl;
		}
	}
}
