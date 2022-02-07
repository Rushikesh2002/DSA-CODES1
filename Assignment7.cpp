#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Graph
{
public:
    int graph[5][5] = {0};

    void Create(map<pair<int, int>, int> distance)
    {
        for (auto x : distance)
        {
            pair<int, int> node = x.first;
            graph[node.first][node.second] = x.second;
        }
    }

    void DisplayMatrix()
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }
    }

    void DisplayGraph(map<int, string> department)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (graph[i][j] > 0)
                {
                    cout << department[i] << " --> " << department[j] << "\n Distance:- " << graph[i][j] << endl;
                    cout << endl;
                }
            }
        }
    }

    pair<int, int> getmin(vector<int> &key, map<pair<int, int>, bool> &mst, map<int, bool> &checkall)
    {
        int min = INT_MAX, idx1 = 0, idx2 = 0;
        for (auto x : key)
        {
            for (int i = 0; i < 5; i++)
            {
                pair<int, int> mk(x, i);
                if (!mst[mk] && graph[x][i] > 0 && graph[x][i] <= min)
                {
                    min = graph[x][i];
                    idx1 = x;
                    idx2 = i;
                }
            }
        }
        pair<int, int> mk(idx1, idx2);
        mst[mk] = true;
        checkall[idx1] = true;
        key.push_back(idx2);
        return mk;
    }

    bool check(map<int, bool> &checkall)
    {

        for (auto x : checkall)
        {
            if (x.second == false)
                return false;
        }
        return true;
    }

    void createprim(map<int, bool> &checkall, map<pair<int, int>, bool> &mst, vector<int> &key, map<int, string> department, map<pair<int, int>, int> distance)
    {

        while (!check(checkall))
        {
            pair<int, int> x = getmin(key, mst, checkall);
            cout << department[x.first] << " --> " << department[x.second] << " --> " << distance[x] << endl;
        }
    }
};

int main()
{

    map<int, string> department;
    department[0] = "office";
    department[1] = "Printing";
    department[2] = "Mechanical";
    department[3] = "IT";
    department[4] = "EnTC";

    map<pair<int, int>, int> distance;
    pair<int, int> office(0, 1), print, mech, it, entc;
    distance[office] = 1;
    office = make_pair(0, 2);
    distance[office] = 2;
    office = make_pair(0, 3);
    distance[office] = 3;
    office = make_pair(0, 4);
    distance[office] = 4;
    print = make_pair(1, 3);
    distance[print] = 2;
    mech = make_pair(2, 4);
    distance[mech] = 2;
    it = make_pair(3, 0);
    distance[it] = 3;
    entc = make_pair(4, 1);
    distance[entc] = 3;

    map<pair<int, int>, bool> mst;
    map<int, bool> checkall;

    vector<int> keys;

    keys.push_back(0);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            pair<int, int> mk(i, j);
            mst[mk] = false;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        checkall[i] = false;
    }
    Graph g = Graph();
    g.Create(distance);

    cout << "Press 1 to Display Adjacent Matrix." << endl;
    cout << "Press 2 to Display Graph" << endl;
    cout << "Press 3 to Minimum Spanning Tree." << endl;
    cout << "Press 4 to Exit" << endl;
    bool check = true;
    while (check)
    {
        cout << "Enter OPTION:- " << endl;
        int ask;
        cin >> ask;
        switch (ask)
        {

        case 1:
            g.DisplayMatrix();
            cout << endl;
            break;
        case 2:
            g.DisplayGraph(department);
            cout << endl;
            break;

        case 3:
            g.createprim(checkall, mst, keys, department, distance);
            cout << endl;
            break;
        case 4:
            check = false;
            break;

        default:
            break;
        }
    }
}