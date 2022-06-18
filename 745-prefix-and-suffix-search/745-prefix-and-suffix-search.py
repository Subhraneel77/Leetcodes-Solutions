class WordFilter:

    def __init__(self, words: List[str]):
        
        # Important: in we do not want duplicate words in our tries and we only want the one with 
        # the largest index. Therefore, we use a table to store the largest index of each word.
        filtered_words = dict()
        for ind, word in enumerate(words):
            filtered_words[word] = ind
            
        # Here we declare two tries, one for the prefix and the other for the suffix
        self.trie = dict()
        self.suf_trie = dict()
        
        # Building up the tries
        for word, index in filtered_words.items():
            iterator = self.trie
            iterator_suf = self.suf_trie
            pos = 0
            pos_suf = len(word) - 1
            while pos != len(word):
                if word[pos] not in iterator:
                    iterator[word[pos]] = dict()
                if word[pos_suf] not in iterator_suf:
                    iterator_suf[word[pos_suf]] = dict()
                iterator = iterator[word[pos]]
                iterator_suf = iterator_suf[word[pos_suf]]
                pos += 1
                pos_suf -= 1
                
                # Since we find words by prefix and suffix, we store the index of the word 
                # at every step as we build up the two tries.
                if '*' not in iterator:
                    iterator['*'] = []
                iterator['*'].append(index)
                if '*' not in iterator_suf:
                    iterator_suf['*'] = []
                iterator_suf['*'].append(index)
                
                    

    def f(self, prefix: str, suffix: str) -> int:
        
        # Check if the prefix and the suffix exist in our tries, if yes, we have a list of word indices 
        # that indicate the words that match the prefix or the suffix. Otherwise, we only have an empty list.
        iterator = self.trie
        pref_ind = []
        for idx, char in enumerate(prefix):
            if char in iterator:
                iterator = iterator[char]
                if idx == len(prefix) - 1:
                    pref_ind = iterator['*']
            else:
                break
        
        iterator_suf = self.suf_trie
        suf_ind = []
        for idx, char in enumerate(suffix[::-1]):
            if char in iterator_suf:
                iterator_suf = iterator_suf[char]
                if idx == len(suffix) - 1:
                    suf_ind = iterator_suf['*']
            else:
                break
        
        # At the end, find out the largest index that exists in both the prefix and the suffix tries.
        cnt = collections.Counter(pref_ind)
        largest = -1
        for suf in suf_ind:
            if suf in cnt:
                largest = max(largest, suf)
        return largest


# Your WordFilter object will be instantiated and called as such:
# obj = WordFilter(words)
# param_1 = obj.f(prefix,suffix)