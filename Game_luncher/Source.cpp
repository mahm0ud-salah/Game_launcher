#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
#define nl "\n"
#define M_S std::ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool flag = true;
bool flag2 = true;
vector<pair<int, int>>v(1);
int x;
class game1 {
private:
	int sx = 10,sy=10, fx = rand() % 25, fy = rand() % 25, my = 0, mx = 1, score = 0, siz = 1, f = 1, f2 = siz, ma = 0;
public:
	game1(int x)
	{
		if (x == 1)
		{
			solve();
		}
		else if (x == 2)
		{
			cout << "*******************************************************" << nl;
			cout << "*snake game 2022  coding by Mahmoud_Salah just that :)*\n";
			cout << "*******************************************************" << nl;
			cout << "Now\n1 - Start ? \nany key - Out ? " << nl;
			cin >> x;
			if (x == 1)
			{
				solve();
			}
			else
			{
				cout << "Goodbye Bro" << nl;
			}
		}
		else
		{
			cout << "1-don't touch walls\n2-don't touch yourself :)\n Now\n 1-Start?\nany key-Out?";
			cin >> x;
			if (x != 1)
				cout << "Goodbye Bro" << nl;
			else
			{
				solve();
			}

		}
	}
	void print()
	{
		f = 1;
		f2 = siz;
		v[0].first = sx;
		v[0].second = sy;
		system("cls");
		for (int i = 1; i < siz; i++)
		{
			if (v[i].first == sx && v[i].second == sy)
			{
				flag = false;
				break;
			}
		}
		cout << "##########################" << nl;
		for (int j = 0; j < 26; j++)
		{
			for (short i = 0; i < 24; i++)
			{
				if (i == 0)
					cout << "#";
				if (v[0].first == i && v[0].second == j)
					cout << 'O';
				else if (f < siz && v[f].first == i && v[f].second == j)
				{

					cout << 'o';
					f++;
				}
				else if (f2 > 1 && v[f2 - 1].first == i && v[f2 - 1].second == j)
				{

					cout << 'o';
					f2--;
				}
				else if (i == fx && j == fy)
					cout << '@';
				else
				{
					cout << ' ';
				}
				if (sx == fx && sy == fy)
				{
					fx = rand() % 25;
					fy = rand() % 25;
					score += 10;
					siz++;
					v.resize(siz);
				}
			}
			cout << '#' << nl;
		}
		cout << "##########################" << nl;
	}
	void move()
	{
		for (int i = siz - 1; i > 0; i--)
		{
			v[i].first = v[i - 1].first;
			v[i].second = v[i - 1].second;
		}
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'a':
				sx--;
				mx = -1;
				my = 0;
				break;
			case 'd':
				sx++;
				mx = 1;
				my = 0;
				break;
			case 's':
				sy++;
				mx = 0;
				my = 1;
				break;
			case 'w':
				sy--;
				mx = 0;
				my = -1;
				break;
			}
		}
		else
		{
			sx += mx;
			sy += my;
		}

	}
	void solve()
	{
		while (1)
		{
			flag = true;
			sx = 10;
			sy = 10;
			fx = rand() % 25;
			fy = rand() % 25;
			mx = 1;
			my = 0;
			score = 0;
			siz = 1;
			while (1)
			{
				ma = max(score, ma);
				print();
				if (sx == 24 || sy == 26 || sx == -1 || sy == -1)
				{
					break;
				}
				move();
				if (!flag)
					break;
				cout << "Your Score is : " << score << nl;
				cout << "Best Scort is : " << ma;
			}
			cout << "Game over " << nl << "Your Score is : " << score << nl << "Best Scort is : " << ma << nl << nl;
			cout << "press 1 to play again or press any other key to out" << nl;
			cin >> x;
			if (x != 1)
			{
				cout << "Goodbye Bro" << nl;
				break;
			}
		}
	}
};
class game2 {
private:
	pair<int, int>ball;
	pair<int, int>one;
	pair<int, int>tow;
	int my = 1, mx = 0;
public:
	game2(int x)
	{
		if (x == 1)
		{
			solve();
		}
		else if (x == 2)
		{
			cout << "*************************************************" << nl;
			cout << "*Ball Game  coding by Mahmoud_Salah just that :)*\n";
			cout << "*************************************************" << nl;
			cout << "Now\n1 - Start ? \nany key - Out ? " << nl;
			cin >> x;
			if (x == 1)
			{
				solve();
			}
			else
			{
				cout << "Goodbye Bro" << nl;
			}
		}
		else if (x == 3)
		{
			cout << "Try To keep Ball far from your Wall\n Now\n 1-Start?\nany key-Out?" << nl;
			cin >> x;
			if (x != 1)
				cout << "Goodbye Bro" << nl;
			else
			{
				solve();
			}
		}
		else
		{
			cout << "Player 1 controls a,d \n Player 2 controls j,l\n Now\n 1-Start?\nany key-Out?" << nl;
			cin >> x;
			if (x != 1)
				cout << "Goodbye Bro" << nl;
			else
			{
				solve();
			}
		}
	}
	void print()
	{
		system("cls");
		cout << "###################################" << nl;
		for (int i = 1; i <= 25; i++)
		{
			for (int j = 1; j <= 35; j++)
			{
				if (ball.second == 26 || ball.second == 0)
					flag = false;
				else if (j == 1 || j == 35)
					cout << '#';
				else if ((i == 1 && j >= one.first && j <= one.second) || (i == 25 && j >= tow.first && j <= tow.second))
					cout << '@';
				else
					cout << ' ';
				if (j == ball.first && i == ball.second)
				{
					cout << 'O';
					j++;
				}
			}
			cout << nl;
		}
		cout << "###################################" << nl;
	}
	void move()
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'a':
				one.first--;
				one.second--;
				break;
			case'd':
				one.first++;
				one.second++;
				break;
			case 'j':
				tow.first--;
				tow.second--;
				break;
			case'l':
				tow.first++;
				tow.second++;
				break;
			}
		}
	}
	void ballmove()
	{
		if (ball.first == 1)
			mx = 1;
		else if (ball.first == 34)
			mx = -1;
		if (ball.second == 2) {
			if (ball.first >= one.first && ball.first <= one.second)
			{
				if (ball.first == one.first || ball.first == one.first + 1)
				{
					mx = 1;
					my = 1;
				}
				else if (ball.first == one.first + 2 || ball.first == one.first + 3)
					my = 1;
				else
				{
					mx = -1;
					my = 1;
				}
			}
			else
				ball.first = 0;
		}
		else if (ball.second == 24)
		{
			if (ball.first >= tow.first && ball.first <= tow.second)
			{
				if (ball.first == tow.first || ball.first == tow.first + 1)
				{
					mx = 1;
					my = -1;
				}
				else if (ball.first == tow.first + 2 || ball.first == tow.first + 3)
					my = -1;
				else
				{
					mx = -1;
					my = -1;
				}
			}
			else
				ball.first = 26;
		}
		ball.first += mx;
		ball.second += my;
	}
	void solve() {
		while (1)
		{
			ball.first = 18; ball.second = 2;
			one.first = 15;
			one.second = 20;
			tow.first = 15;
			tow.second = 20;
			my = 1;
			mx = 0;
			while (flag)
			{
				print();
				move();
				ballmove();
			}
			cout << "Game Over press 1 to play again or press any other key to out" << nl;
			cin >> x;
			if (x != 1)
			{
				cout << "Goodbye Bro" << nl;
				break;
			}
			else
				flag = true;

		}
	}
};
int main()
{
	M_S
		cout << "WELCOME TO M_S GAME LUNCHER v1.1 :-)" << nl;
	cout << "to Play snke game press 1" << nl << "to Play ball game (new in this update) press 2" << nl;
	short t;
	while (true)
	{
		cin >> t;
		if (t == 1)
		{
			cout << "Snake Game 2022" << nl;
			cout << "1-start\n2-credits\n3-How to play\n";
			cout << "*****************************" << nl;
			cout << "* game controls a,s,d and w *" << nl;
			cout << "*****************************" << nl;
			cin >> x;
			game1 ob(x);
			break;

		}
		else if (t == 2)
		{
			flag = true;
			cout << "Welcome Ball Gaeme" << nl;
			cout << "*****************************" << nl;
			cout << "1-start\n2-credits\n3-How to play\n4-Controls\n";
			cout << "*****************************" << nl;
			cin >> x;
			game2 ob(x);
			break;
		}
		else cout << "please enter 1 or 2 :)" << nl;
	}
}