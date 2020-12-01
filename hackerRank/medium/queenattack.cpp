#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the queensAttack function below.
int queensAttack(int k, int n, int r_q, int c_q, vector<vector<int>> obstacles) {
    cout << k << endl;
    int direct[8][2];
    direct[0][0] = r_q;
    direct[0][1] = 0;
    direct[1][0] = r_q;
    direct[1][1] = k+1;

    direct[2][0] = 0;
    direct[2][1] = c_q;
    direct[3][0] = k+1;
    direct[3][1] = c_q;

    if(r_q + c_q < k + 1){
        direct[4][0] = 0;
        direct[4][1] = r_q + c_q;
        direct[5][0] = r_q + c_q;
        direct[5][1] = 0;
    }
    else if(r_q + c_q > k + 1){
        direct[4][0] = r_q + c_q - k - 1;
        direct[4][1] = k+1;
        direct[5][0] = k+1;
        direct[5][1] = r_q + c_q - k - 1;
    }
    else{
        direct[4][0] = 0;
        direct[4][1] = k+1;
        direct[5][0] = k+1;
        direct[5][1] = 0;
    }

    if(r_q - c_q > 0){
        direct[6][0] = r_q - c_q;
        direct[6][1] = 0;
        direct[7][0] = k+1;
        direct[7][1] = k+1 - (r_q - c_q);
    }
    else if(r_q - c_q < 0){
        direct[6][0] = 0;
        direct[6][1] = c_q - r_q;
        direct[7][0] = k+1 - (c_q - r_q);
        direct[7][1] = k+1;
    }
    else{
        direct[6][0] = 0;
        direct[6][1] = 0;
        direct[7][0] = k+1;
        direct[7][1] = k+1;
    }
    cout << direct[1][1] << "   "<< direct[0][1] << endl;
    int diagconst1 = r_q + c_q;
    int diagconst2 = r_q - c_q;
    if(n > 0)
    for(int i = 0; i < obstacles.size(); i++)
    {

        if(obstacles[i][0] == r_q){//проверяет ряд
            if(c_q - obstacles[i][1] > 0){//left
                if(direct[0][1] - obstacles[i][1] < 0){
                    direct[0][0] = obstacles[i][0];
                    direct[0][1] = obstacles[i][1];
                }
            }
            else{//right
                if(direct[1][1] - obstacles[i][1] > 0){
                    direct[1][0] = obstacles[i][0];
                    direct[1][1] = obstacles[i][1];
                }
            }
        }
        else if(obstacles[i][1] == c_q){//проверяет не в том же столбце
            if(r_q - obstacles[i][0] > 0){//up
                if(direct[2][0] - obstacles[i][0] < 0){
                    direct[2][0] = obstacles[i][0];
                    direct[2][1] = obstacles[i][1];
                }
            }
            else{//down
                if(direct[2][0] - obstacles[i][0] > 0){
                    direct[2][0] = obstacles[i][0];
                    direct[2][1] = obstacles[i][1];
                }
            }
        }
        else if(obstacles[i][0] + obstacles[i][1] == diagconst1){
            if(r_q - obstacles[i][0] > 0){//up
                if(direct[4][0] - obstacles[i][0] < 0){
                    direct[4][0] = obstacles[i][0];
                    direct[4][1] = obstacles[i][1];
                }
            }
            else{//down
                if(direct[5][0] - obstacles[i][0] > 0){
                    direct[5][0] = obstacles[i][0];
                    direct[5][1] = obstacles[i][1];
                }
            }
        }
        else if(obstacles[i][0] - obstacles[i][1] == diagconst2){
            if(r_q - obstacles[i][0] > 0){//up
                if(direct[6][0] - obstacles[i][0] < 0){
                    direct[6][0] = obstacles[i][0];
                    direct[6][1] = obstacles[i][1];
                }
            }
            else{//down
                if(direct[7][0] - obstacles[i][0] > 0){
                    direct[7][0] = obstacles[i][0];
                    direct[7][1] = obstacles[i][1];
                }
            }
        }
    }
    int sum = 0;
    sum += direct[1][1] - direct[0][1] - 2;

    sum += abs(direct[2][0] - direct[3][0]) - 2;

    sum += abs(direct[4][0] - direct[5][0]) - 2;

    sum += abs(direct[6][0] - direct[7][0]) - 2;

    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

    cout << result << "\n";



    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
