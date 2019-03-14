/*
 Find the original (unscrambled) words, which were randomly taken from a wordlist.
 Send a comma separated list of the original words, in the same order as in the list below.
 You have 30 seconds time to send the solution.
*/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

/*
 Puts ascii value of lowercase letters in the word into an array.
 Sorts array and converts into string again
 Returns word with characters in alphabetical order
*/
std::string Alphabetizer(std::string word)
{
    std::vector<int> characters;

    //Fill vector with ascii values of word
    for(int i=0; i < word.length(); i++) 
    {
        characters.push_back(std::tolower(int(word[i])));
    }

    std::sort(characters.begin(),characters.end()); //Sorts the array

    std::string alpha_word = "";

    //Put the string in alphabetical order
    for(int j=0; j < characters.size(); j++)
    {
       alpha_word += char(characters[j]);
    } 

    return alpha_word;
}

/*
 Takes in ordered string.
 Goes through wordlist, runs Alphabetizer on them and compares them to given word.
 Returns correct word from wordlist that matches original scrambled word.
*/
std::string Comparer(std::string alpha_word)
{
    //Open wordlist and iterate through the lines
    std::fstream wordlist("wordlist.txt");
    std::string line;
    while(std::getline(wordlist, line))
    {
        line = line.substr(0,line.length()-1); //Removes newline character from end of string

        //Compare word from wordlist to the initially given word and return correct word if they match
        if(Alphabetizer(line).compare(alpha_word) == 0)
        {
            return line;
        }
    }
    return "Something went horribly wrong";
}


int main()
{
    std::string comma_list = "";
    for(int i=1; i <= 10; i++)
    {
        std::string s = "";
        std::cin >> s;

        std::string ordered_word = Alphabetizer(s);
        std::string correct_word = Comparer(ordered_word);
        comma_list += correct_word + ",";
    }
    comma_list = comma_list.substr(0,comma_list.length()-1); //Gets rid of last comma
    std::cout << comma_list;
    
    return 0;
}
