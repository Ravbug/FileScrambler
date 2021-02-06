# pragma once
#include <filesystem>
#include <vector>
#include <string>

/**
 * Defines a scrambler object.
 * This could have been just a simple function, however an earlier design contained complexity that required an object.
 */
class Scrambler{
public:
	/**
	 Create a scrambler
	 @param p the path to the root directory to perform scrambling
	 @param skip filenames containing these patterns will not be touched
	 @param invert only items in the skip list will be touched
	 @param penultimate scramble up one directory instead of filenames
	 */
	Scrambler(const std::filesystem::path& p, const std::vector<std::string>& skip = {}, bool invert = false, bool pen = false, bool r = false) :
	dir(p), skip_if_contains(skip), invert_skip(invert), penultimate(pen), recursive(r) {};
	
	void scramble();
protected:
	/**
	 Get the paths to process
	 @param the vector to write the data into
	 */
	void get_paths(std::vector<std::filesystem::path>&);
	
	
	/**
	 Generate a name for the item to be renamed
	 @param the id for this item
	 @param p the path to this item
	 */
	std::filesystem::path gen_name(const std::string& id, const std::filesystem::path& p);
	
	std::filesystem::path gen_leaf(const std::filesystem::path& path);
	
	/**
	 Reverse gen_name
	 @param p the path to reverse
	 @param name the name to append
	 */
	std::filesystem::path undo_gen_name(const std::filesystem::path& p, const std::string& name);
	
private:
	std::filesystem::path dir;
	std::vector<std::string> skip_if_contains;
	bool invert_skip;
	bool penultimate;
	bool recursive;
};
