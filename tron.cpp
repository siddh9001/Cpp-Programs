#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

int main() {
    vector<string> board;
    string s;
    srand(time(NULL));
    vector<string> moves;
    moves.push_back("UP");
    moves.push_back("DOWN");
    moves.push_back("LEFT");
    moves.push_back("RIGHT");
    vector<int> valid_moves;
    char player;
    int i_x, i_y, o_x, o_y;
    cin>>player>>i_x>>i_y>>o_x>>o_y;
    int x,y;
    if(player == 'r') {
        x = i_x;
        y = i_y;
    } else {
        x = o_x;
        y = o_y;
    }
    for( int i = 0; i < 15; i++ ) cin>>s, board.push_back(s);
    for ( int i = -1; i < 2; i++ ) {
        for ( int j = -1; j < 2; j++) {
            if ((i == 0 && j !=0) || ( i != 0 && j == 0 ) ) {
                if(board[x+i][y+j] == '-') {
                    if( i == -1 ) valid_moves.push_back(0);
                    if( i == 1 ) valid_moves.push_back(1);
                    if( j == -1 ) valid_moves.push_back(2);
                    if( j == 1 ) valid_moves.push_back(3);
                }
            }
        }
    }
    if( valid_moves.size()!=0 ) {
        int random = rand()%valid_moves.size();
        cout<<moves[valid_moves[random]];
        return 0;
    }
    cout<<moves[rand()%moves.size()]<<endl;
    return 0;
}
