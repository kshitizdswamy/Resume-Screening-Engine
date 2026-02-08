#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
using namespace std;

struct Skill {
    int weight;
    int maxCount;
};

void readFileAndCount(
    ifstream &file,
    unordered_map<string, int> &count,
    unordered_map<string, Skill> &skills
)
 {
    string line, word = "";

    while (getline(file, line)) {
        for (int i = 0; i < line.length(); i++) {
            char ch = tolower(line[i]);

            if (ch == ' ') {
                if (skills.find(word) != skills.end()) {
                    count[word]++;
                }
                word = "";
            } else {
                word += ch;
            }
        }

        if (skills.find(word) != skills.end()) {
            count[word]++;
        }
        word = "";
    }
}

int main() {

    unordered_map<string, Skill> skills;
    skills["c++"] = {5, 2};
    skills["python"] = {4, 2};
    skills["java"] = {4, 2};
    skills["react"] = {3, 1};
    skills["node"] = {3, 1};
    skills["database"] = {3, 1};
    skills["server"] = {2, 1};

    unordered_map<string, int> resumeCount;
    unordered_map<string, int> jobCount;

    ifstream resume("resume.txt");
    ifstream job("job.txt");

    if (resume.fail() || job.fail()) {
        cout << "File error" << endl;
        return 0;
    }

    readFileAndCount(resume, resumeCount, skills);
    readFileAndCount(job, jobCount, skills);

    int score = 0;
    int maxScore = 0;

    cout << "Matched Skills:\n";

    for (unordered_map<string, Skill>::iterator it = skills.begin();
         it != skills.end();
         it++) {

        string skillName = it->first;
        Skill rule = it->second;

        if (jobCount[skillName] > 0) {
            maxScore += rule.weight;

            int freq = resumeCount[skillName];
            if (freq > rule.maxCount) {
                freq = rule.maxCount;
            }

            if (freq > 0) {
                cout << "- " << skillName << endl;
                score += rule.weight;
            }
        }
    }

    cout << "\nMissing Skills:\n";
    for (unordered_map<string, Skill>::iterator it = skills.begin();
         it != skills.end();
         it++) {

        string skillName = it->first;

        if (jobCount[skillName] > 0 && resumeCount[skillName] == 0) {
            cout << "- " << skillName << endl;
        }
    }

    cout << "\nScore: " << score << " / " << maxScore << endl;

    if (score >= maxScore * 0.7)
        cout << "Decision: GOOD MATCH\n";
    else if (score >= maxScore * 0.4)
        cout << "Decision: BORDERLINE\n";
    else
        cout << "Decision: REJECT\n";

    return 0;
}
