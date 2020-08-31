#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
 
using namespace std;
 
struct Team{
    int n_games, n_wins, n_ties, n_loss,
        n_goals, n_goals_against, n_points;
    char* name;
    Team(char* TN) {
        name = TN;
        n_games = 0, n_wins = 0, n_ties = 0, n_loss = 0,
            n_goals = 0, n_goals_against = 0, n_points = 0;
    }
    Team(){
        n_games = 0, n_wins = 0, n_ties = 0, n_loss = 0,
            n_goals = 0, n_goals_against = 0, n_points = 0;
    }
};
 
bool teams_comparator(pair<string,Team> e1, pair<string,Team> e2){
    Team t1 = e1.second, t2 = e2.second;
    int p_a = t1.n_wins*3 + t1.n_ties, p_b = t2.n_wins*3 + t2.n_ties;
    int gd_a = t1.n_goals - t1.n_goals_against;
    int gd_b = t2.n_goals - t2.n_goals_against;
  
    if (p_a != p_b) return p_a > p_b;
    if (t1.n_wins != t2.n_wins) return t1.n_wins > t2.n_wins;
    if (gd_a != gd_b) return gd_a > gd_b;
    if (t1.n_goals != t2.n_goals) return t1.n_goals > t2.n_goals;
    if (t1.n_games != t2.n_games) return t1.n_games < t2.n_games;
 
    for(int i=0; i < strlen(t1.name); i++)
        t1.name[i] = tolower(t1.name[i]);
    for(int i=0; i < strlen(t2.name); i++)
        t2.name[i] = tolower(t2.name[i]);
  
    return strcmp( t1.name, t2.name) < 0;
  
}
 
int main(){
    int N; scanf("%d\n", &N);
    for(int n = 0; n<N; n++){
        char t_name[101]; gets(t_name);
        int n_teams; scanf("%d\n", &n_teams);
        map<string, Team> teams;
        for(int nt = 0; nt<n_teams; nt++){
            char team_name[31];
            gets(team_name);
            Team t = Team(team_name);
            teams.insert(make_pair(team_name, t));
        }
 
        int n_games; scanf("%d\n", &n_games);
        char game[1001];
 
        for(int ng = 0; ng<n_games; ng++){
            gets(game);
            int len = strlen(game);
            int i = 0, j = 0;
 
            // Teamname A and B
            char tn_a[31], tn_b[31];
             
            while(game[i]!='#'){tn_a[j++] = game[i++];}
            tn_a[j] = '\0'; j = 0; i++;
 
            // Number of goals characters
            char ngc_a[16], ngc_b[16];
            // Number of goals
            int ng_a, ng_b;
 
            while(game[i]!='@'){ngc_a[j++] = game[i++];}
            ngc_a[j] = '\0'; ng_a = atoi(ngc_a); j = 0; i++;
            while(game[i]!='#'){ngc_b[j++] = game[i++];}
            ngc_b[j] = '\0'; ng_b = atoi(ngc_b); j = 0; i++;
 
            while(game[i]!='\0'){tn_b[j++] = game[i++];}
            tn_b[j] = '\0'; j = 0; i++;
 
            // Getting the reference of the team A and B objects
            Team *ta = & teams[tn_a]; Team *tb = & teams[tn_b];
 
            (ta->n_games)++; (tb->n_games)++;
            ta->n_goals += ng_a; tb->n_goals += ng_b;
            ta->n_goals_against += ng_b; tb->n_goals_against += ng_a;
 
            if(ng_a == ng_b) (ta->n_ties)++, (tb->n_ties)++;
            else if(ng_a > ng_b) (ta->n_wins)++, (tb->n_loss)++;
            else (ta->n_loss)++, (tb->n_wins)++;
        }
        // Creating new vector for sorted teams
        vector< pair<string, Team> > s_teams;
        // Copying all the elements from map to a vector
        copy(teams.begin(), teams.end(), back_inserter(s_teams));
        // Sorting the teams according to the required parameters
        sort(s_teams.begin(), s_teams.end(), teams_comparator);
 
        puts(t_name);
        for (int j = 0; j<s_teams.size(); j++){
            printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
                j+1, s_teams[j].first.c_str(),
                s_teams[j].second.n_wins*3 + s_teams[j].second.n_ties,
                s_teams[j].second.n_games, s_teams[j].second.n_wins,
                s_teams[j].second.n_ties, s_teams[j].second.n_loss,
                s_teams[j].second.n_goals - s_teams[j].second.n_goals_against,
                s_teams[j].second.n_goals, s_teams[j].second.n_goals_against);
        }
        if (n != N-1) printf("\n");
    }
    return 0;
}