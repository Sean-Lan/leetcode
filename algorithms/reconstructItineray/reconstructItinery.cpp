/**
 *
 * Sean
 * 2016-03-17
 *
 * https://leetcode.com/problems/reconstruct-itinerary/
 *
 * Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order.
 * All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.
 *
 * Note:
 * If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.
 * For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
 * All airports are represented by three capital letters (IATA code).
 * You may assume all tickets form at least one valid itinerary.
 *
 * Example 1:
 * tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
 * Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
 *
 * Example 2:
 * tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
 * Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
 * Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.
 *
 */
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

/**
 *
 * DFS with backtracking.
 * 1. construct a map with source as key and sorted destinations as the value.
 * 2. construct a map with source as key and n false boolean value as the value,
 *    where n is the size of the destinations from source.
 * 3. Use DFS to find the possible solution.
 *      From 'JFK', find next available city, then recursive search until success.
 *
 */
class Solution {
    typedef pair<string, string> TicketPair;
    public:
        vector<string> findItinerary(vector<pair<string, string>> tickets) {
            if (tickets.empty()) return {};
            unordered_map<string, vector<string>> destinations;
            for (auto &ticket : tickets)
                destinations[ticket.first].push_back(ticket.second);
            for (auto &aPair : destinations)
                sort(aPair.second.begin(), aPair.second.end());
            unordered_map<string, vector<bool>> takens;
            for (auto &aPair : destinations)
                takens[aPair.first] = vector<bool>(aPair.second.size(), false);
            vector<string> result = { "JFK" };
            string lastTicket = "JFK";
            dfs(destinations, takens, result, lastTicket, tickets.size());
            return result;
        }

    private:
        bool dfs(unordered_map<string, vector<string>> &destinations,
                unordered_map<string, vector<bool>> &takens, vector<string> &current, string lastTicket, const int &n) {
            if (current.size()==n+1)
                return true;
            vector<string> &destination = destinations[lastTicket];
            vector<bool> &taken = takens[lastTicket];
            lastTicket = "";
            for (int i=0; i<destination.size(); ++i) {
                if (!taken[i] && destination[i]!=lastTicket) {
                    lastTicket = destination[i];
                    taken[i] = true;
                    current.push_back(lastTicket);
                    if (dfs(destinations, takens, current, lastTicket, n))
                        return true;
                    current.pop_back();
                    taken[i] = false;
                }
            }
            return false;
        }
};

int main() {
    vector<pair<string, string>> tickets = { { "JFK","KUL" },{ "JFK","NRT" },{ "NRT","JFK" } };
    Solution solution;
    auto result = solution.findItinerary(tickets);
    for (auto &s : result)
        cout << s << " ";
    cout << endl;
}
