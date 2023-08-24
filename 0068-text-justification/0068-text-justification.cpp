class Solution {
public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
        std::vector<std::string> res;

        int i = 0;
        int width = 0;
        std::vector<std::string> curLine;

        while (i < words.size()) {
            std::string curWord = words[i];

            if (width + curWord.length() <= maxWidth) {
                curLine.push_back(curWord);
                width += curWord.length() + 1;
                i++;
            } else {
                int spaces = maxWidth - width + curLine.size();

                int added = 0;
                int j = 0;

                while (added < spaces) {
                    if (j >= curLine.size() - 1) {
                        j = 0;
                    }

                    curLine[j] += " ";
                    added++;
                    j++;
                }

                std::string line = "";
                for (const std::string& word : curLine) {
                    line += word;
                }
                res.push_back(line);

                curLine.clear();
                width = 0;
            }
        }

        for (int word = 0; word < curLine.size() - 1; word++) {
            curLine[word] += " ";
        }
        curLine[curLine.size() - 1] += std::string(maxWidth - width + 1, ' ');

        std::string lastLine = "";
        for (const std::string& word : curLine) {
            lastLine += word;
        }
        res.push_back(lastLine);

        return res;
    }
};