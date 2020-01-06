#ifndef SINGLE_TURN_CONVERSATION_DISTINCT_H
#define SINGLE_TURN_CONVERSATION_DISTINCT_H


#include <vector>
#include <string>
#include <iostream>
#include <set>

using namespace std;

const vector<string> ngram_sentence_level(const vector<string> &sentence, int gram_len) {
    vector<string> ngram_vec;
    for(int i = 0; i < sentence.size() + 1 - gram_len; ++i) {
        string ngram("");
        for (int j = i; j <= i + gram_len - 1; ++j) {
            ngram += sentence.at(j);
        }
        ngram_vec.emplace_back(ngram);
    }
    return ngram_vec;
} 

float computeDistinct(const vector<vector<string>> &sentences, int gram_len) {
    float sum = 0.0f;
    for (const auto & sentence : sentences) {
        if (sentence.size() < gram_len) {
            sum += 0.0f;
        } else {
            const auto &ngram_vec = ngram_sentence_level(sentence, gram_len);
            int word_cnt = ngram_vec.size();
            set<string>unique_set(ngram_vec.begin(), ngram_vec.end());
            int unique_cnt = unique_set.size();
            sum += (unique_cnt * 1.0f / word_cnt);
        }
    }
    return sum / sentences.size();
}

#endif // SINGLE_TURN_CONVERSATION_DISTINCT_H