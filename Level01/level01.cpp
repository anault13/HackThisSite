/*
 * Find the original (unscrambled) words, which were randomly taken from a wordlist.
 * Send a comma separated list of the original words, in the same order as in the list below.
 * You have 30 seconds time to send the solution.
 */
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

/*
 * Puts ascii value of lowercase letters in the word into an array.
 * Sorts array and converts into string again
 * Returns word with characters in alphabetical order
 */
std::string alphabetizer(std::string word)
{
    std::vector<int> characters;
    std::string alpha_word = "";
 
    // Fill vector with ascii values of word
    for (int i = 0; i < word.length(); i++) 
    {
        characters.push_back(std::tolower(int(word[i])));
    }
 
    // Sorts the array
    std::sort(characters.begin(), characters.end());

    // Put the string in alphabetical order
    for (int i = 0; i < characters.size(); i++)
    {
       alpha_word += char(characters[i]);
    }

    return alpha_word;
}

/*
 * Takes in ordered string.
 * Goes through wordlist, runs Alphabetizer on them and compares them to given word.
 * Returns correct word from wordlist that matches original scrambled word.
 */
std::string comparer(std::string alpha_word)
{
    std::string line = "";
 
    // Open wordlist and iterate through the lines
    std::fstream wordlist("wordlist.txt");

    while(std::getline(wordlist, line))
    {
        // Removes newline character from end of string
        line = line.substr(0, line.length() - 1);

        // Compare word from wordlist to the initially given word and return correct word if they match
        if (0 == alphabetizer(line).compare(alpha_word))
        {
            return line;
        }
    }
 
    return "Something went horribly wrong";
}

int main()
{
    std::string comma_list = "";
 
    for (int i = 0; i < 10; i++)
    {
        std::string scrambled_word = "";
        std::cin >> scrambled_word;

        std::string ordered_word = alphabetizer(scrambled_word);
        std::string correct_word = comparer(ordered_word);
        comma_list += correct_word + ",";
    }
 
    // Gets rid of last comma
    comma_list = comma_list.substr(0, comma_list.length() - 1);
    std::cout << comma_list;
    
    return 0;
}
