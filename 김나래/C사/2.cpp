#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <map>

using namespace std;

int main() {
	string line;
	ifstream in("input.txt");
	map<string, set<string>> cluster;
	vector<pair<string, int>> input;
	map<string, set<string>>::iterator it;

	if (in.is_open())
	{
		getline(in, line);
		int N = stoi(line);

		for (int i = 0; i < N; ++i) {
			getline(in, line);
			int t = 0;
			while (line[t] != ',') t++;
			input.push_back(make_pair(line.substr(0, t)
				, stoi(line.substr(t + 1, line.length() - t))
			));
		}

		getline(in, line);
		int clsN = stoi(line);
		for (int i = 0; i < clsN; ++i) {
			getline(in, line);
			int t = 0;
			while (line[t] != ',') t++;

			string s1 = line.substr(0, t);
			string s2 = line.substr(t + 1, line.length() - t);
			bool exist = false;

			for (it = cluster.begin(); it != cluster.end(); ++it) {
				if (it->second.find(s1) != it->second.end()) {
					it->second.insert(s2);
					exist = true;
					break;
				}
				if (it->second.find(s2) != it->second.end()) {
					exist = true;
					it->second.insert(s1);
					break;
				}
			}
			if (!exist) {
				set<string> tmp;
				tmp.insert(s1);
				tmp.insert(s2);
				cluster.insert(make_pair(s1, tmp));
			}
		}


		it = cluster.begin();
		while (it != cluster.end()) {
			int max = 0;
			string center;
			for (int j = 0; j < input.size(); ++j) {
				if (it->second.find(input[j].first) != it->second.end()) {
					if (max < input[j].second) {
						max = input[j].second;
						center = input[j].first;
					}
				}
			}
			if (it->first != center) {
				cluster.insert(make_pair(center, it->second));
				it = cluster.erase(it++);
			}
			else
				it++;
		}

		map<string, int> res;
		for (int j = 0; j < input.size(); ++j) {
			bool exist = false;
			for (it = cluster.begin(); it != cluster.end(); ++it) {
				if (it->second.find(input[j].first) != it->second.end()) {
					if (res.find(it->first) != res.end()) {
						res[it->first] += input[j].second;
					}
					else
						res.insert(make_pair(it->first, input[j].second));
					exist = true;
				}
			}
			if (!exist)
				res.insert(input[j]);
		}

		in.close();

		ofstream out("output.txt");
		out << res.size() << endl;
		if (out.is_open())
		{
			map<string, int>::iterator it;
			for (it = res.begin(); it != res.end(); ++it)
				out << it->first << "," << it->second << endl;

			out.close();
		}

	}

	return 0;
}