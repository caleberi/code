#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

vector<string> split_string(string);

void add_to_team(vector<int> &team, int val)
{
        bool add = false;
        for (auto &fighter : team)
        {
                if (val >= fighter)
                        add = true;
                add = false;
        }
        if (add)
                team.push_back(val);
}

int find_winner(pair<int, vector<int>> x, pair<int, vector<int>> y)
{
        sort(x.second.begin(), x.second.end(), [&](int a, int b) -> bool {
                return a > b ? true : false;
        });
        sort(y.second.begin(), y.second.end(), [&](int a, int b) -> bool {
                return a > b ? true : false;
        });
        int team_x = 0; // undead fighers
        int team_y = 0;
        do
        {
                if (team_x >= x.second.size())
                        return y.first;
                team_y += x.second[team_x];
                if (team_y >= y.second.size())
                        return x.first;
                team_x += y.second[team_y];
        } while (true);
}

vector<int> fightingPits(int k, vector<vector<int>> fighters, vector<vector<int>> queries)
{
        //queries -> {{},{}}
        vector<int> res;
        unordered_map<int, vector<int>> teams_strength;
        if (queries.size() == 0 || fighters.size() == 0)
                return res;

        int len_of_fighters = fighters.size();
        for (int i = 0; i < len_of_fighters; i++)
        {
                int key = fighters[i][1];
                if (teams_strength.find(key) == teams_strength.end())
                        teams_strength[fighters[i][1]] = vector<int>();
                teams_strength[fighters[i][1]].push_back(fighters[i][0]); // {1:{1,2,1,2,4}} eg for each team
        }

        int len_of_queries = queries.size();
        for (int i = 0; i < len_of_queries; i++)
        {
                if (queries[i][0] == 1)
                        add_to_team(teams_strength[queries[i][2]], queries[i][1]);
                if (queries[i][0] == 2)
                {
                        auto x = teams_strength.find(queries[i][1]);
                        if (x == teams_strength.end())
                                continue;

                        auto y = teams_strength.find(queries[i][2]);
                        if (y == teams_strength.end())
                                continue;
                        int v = find_winner(*x, *y);
                        res.push_back(v);
                }
        }

        return res;
}

int main()
{
        ofstream fout(getenv("OUTPUT_PATH"));

        string nkq_temp;
        getline(cin, nkq_temp);

        vector<string> nkq = split_string(nkq_temp);

        int n = stoi(nkq[0]);

        int k = stoi(nkq[1]);

        int q = stoi(nkq[2]);

        vector<vector<int>> fighters(n);
        for (int fighters_row_itr = 0; fighters_row_itr < n; fighters_row_itr++)
        {
                fighters[fighters_row_itr].resize(2);

                for (int fighters_column_itr = 0; fighters_column_itr < 2; fighters_column_itr++)
                {
                        cin >> fighters[fighters_row_itr][fighters_column_itr];
                }

                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        vector<vector<int>> queries(q);
        for (int queries_row_itr = 0; queries_row_itr < q; queries_row_itr++)
        {
                queries[queries_row_itr].resize(3);

                for (int queries_column_itr = 0; queries_column_itr < 3; queries_column_itr++)
                {
                        cin >> queries[queries_row_itr][queries_column_itr];
                }

                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        vector<int> result = fightingPits(k, fighters, queries);

        for (int result_itr = 0; result_itr < result.size(); result_itr++)
        {
                fout << result[result_itr];

                if (result_itr != result.size() - 1)
                {
                        fout << "\n";
                }
        }

        fout << "\n";

        fout.close();

        return 0;
}

vector<string> split_string(string input_string)
{
        string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
                return x == y and x == ' ';
        });

        input_string.erase(new_end, input_string.end());

        while (input_string[input_string.length() - 1] == ' ')
        {
                input_string.pop_back();
        }

        vector<string> splits;
        char delimiter = ' ';

        size_t i = 0;
        size_t pos = input_string.find(delimiter);

        while (pos != string::npos)
        {
                splits.push_back(input_string.substr(i, pos - i));

                i = pos + 1;
                pos = input_string.find(delimiter, i);
        }

        splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

        return splits;
}
