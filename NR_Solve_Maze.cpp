#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> & NR_Solve_Maze(vector<vector<int>> maze, int start , int finish, vector<int>&path)
{
    int currentPoint = start;
    unordered_set<int> visited;
    visited.insert(currentPoint);
    path.push_back(currentPoint);

    while(!path.empty() && path.back() != finish)
    {
        vector<int>:: iterator it = maze[currentPoint].begin();
        bool foundOut = false;
        while(it != maze[currentPoint].end() && !foundOut)
        {
            if(visited.count(*it) == 0)
            {
                foundOut = true;
            }
            else it++;
        }

        if(foundOut)
        {
            visited.insert(*it);
            path.push_back(*it);
        }
        else
        {
            path.pop_back();
        }
        currentPoint = path.back();
    }
    return path;
}

bool R_Solve_Maze(vector<vector<int>> maze, int start, int finish, unordered_set<int> & visited,
vector<int> &path)
{
    if(start == finish)
    {
        path.insert(path.begin(), start);
        return true;
    }

    visited.insert(start);
    vector<int>:: iterator it = maze[start].begin();
    while(it != maze[start].end())
    {
        if(visited.count(*it) == 0)
        {
            if(R_Solve_Maze(maze, *it, finish, visited, path))
            {
                path.insert(path.begin(), start);
                return true;
            }
        }
        it++;
    }
    return false;
}

int main()
{
    vector<vector<int>> maze(9);
    maze[0].push_back(1);
    maze[0].push_back(3);
    maze[1].push_back(2);
    maze[3].push_back(4);
    maze[3].push_back(6);
    maze[4].push_back(5);
    maze[4].push_back(7);
    maze[7].push_back(8);
    vector<int> path;
    unordered_set<int> visited;
    R_Solve_Maze(maze, 0, 8, visited, path);
    // NR_Solve_Maze(maze, 0, 8, path);

    if(path.size() == 0)
    {
        cout << "No possible path.\n";
        return 0;
    }
    for(int i = 0; i < path.size()-1; i++)
    {
        cout << path[i] << " ->";
    }
    cout << path[path.size()- 1] << endl;
    return 0;
}