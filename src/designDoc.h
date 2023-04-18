//This file is for documentation purposes only. It will be ignored by the compiler.
//Our Teaching Assistant will manually grade this file.

//Please make sure that you include the entire content of this file as comments.

/* Design Doc: communicate your thought process in English.

0. List of members who contributed to the implementation of this project:
    Abdarrahman Ayyaz
    Dyllan Grossman
    Elliot Warren
    Mohammed Deeb

1. Describe your algorithm for the sentenceSplitter( ) function in pseudocode.

    sentenceSplitter()
        stuff

2. Describe your algorithm for the wordpairMapping( ) function in pseudocode.

    wordpairMapping()
        stuff
        //Feel free to edit this if you think you can make it sound better for her requirements.
        
        
        function wordpairMapping(const sentences: vector<string>, wordpairFreq_map: map<pair<string, string>, int>)
    for each sentence in sentences do
        tokens = empty vector of strings
        tokenMaker(tokens, sentence) // tokenize the sentence
         pairMaker(tokens, pairs) // make pairs
        for i = 0 to tokens.size() - 2 then
            for j = i + 1 to tokens.size() - 1 then
                first = tokens[i]
                second = tokens[j]
                if (first > second) then // arrange the pair in lexicographical order
                    swap(first, second)
                pair = make_pair(first, second)
                if (pair is not in seen_pairs) then // only count each pair once per sentence
                    wordpairFreq_map[pair]++
                    insert pair into seen_pairs
                end of if
            end of for
        end of for
    end of for
end of function


*/
