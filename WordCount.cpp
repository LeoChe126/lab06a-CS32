// WordCount.cpp

#include "WordCount.h"

using namespace std;

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(std::string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
	int totalWords = 0; 
	for(size_t i = 0; i < CAPACITY; i++){
		for(const auto& pair : table[i]){
			totalWords += pair.second;
		}
	}
	return totalWords;
}

int WordCount::getNumUniqueWords() const {
	int numUniqueWords = 0;
	for(size_t i = 0; i < CAPACITY; i++){
		numUniqueWords += table[i].size();
	}
	return numUniqueWords;
}

int WordCount::getWordCount(std::string word) const {
	word = makeValidWord(word);
	if(word.empty()){
		return 0;
	}
	size_t idx = hash(word);
	for(const auto& pair : table[idx]){
		if(pair.first == word){
			return pair.second;
		}
	}
	return 0;
}
	
int WordCount::incrWordCount(std::string word) {
	word = makeValidWord(word);
	if(word.empty()){
		return 0;
	}
	size_t idx = hash(word);
	for(auto& pair : table[idx]){
		if(pair.first == word){
			return ++pair.second;
		}
	}
	table[idx].emplace_back(word, 1);
	return 1;
}

int WordCount::decrWordCount(std::string word) {
	word = makeValidWord(word);
	if(word.empty()){
		return -1;
	}
	size_t idx = hash(word);
	for(auto it = table[idx].begin(); it != table[idx].end(); it++){
		if(it->first == word){
			if(it->second > 1){
				return --(it->second);
			}
			else{
				table[idx].erase(it);
				return 0;
			}
		}
	}
	return -1;
}

bool WordCount::isWordChar(char c) {
	// bool isValid = false;
	// if(isalpha(c) != true){
	// 	return isValid;
	// }
	// else{
	// 	isValid = true;
	// 	return isValid;
	// }
	return isalpha(c);
}

std::string WordCount::makeValidWord(std::string word) {
	string validWord = "";
	for(size_t i = 0; i < word.size(); i++){
		if(isWordChar(word[i])){
			validWord += tolower(word[i]);
		}
		else if((word[i] == '-' || word[i] == '\'') && (i > 0 && i < word.size() - 1) && (isWordChar(word[i - 1]) && isWordChar(word[i + 1]))){
			validWord += word[i];
		}
	}
	return validWord;

}
