#include "SFML/Graphics.hpp"
#include <vector>

Color colors[10] = { Color::Red, Color::Green, Color::Magenta, Color::Blue, Color::White };
const std::string Pposition[5] = { "1st", "2rd", "3rd", "4th", "5th" };
const std::string Racer[5] = { "You", "Dominic Toretto", "Brian O'Conner", "Luke Hobbs", "Han Lue" };

bool Up = 0, Right = 0, Down = 0, Left = 0, Drift = 0, Sprint = 0;
bool Firing = false, Spraying = false;
bool _Bul = 0, _Las = 0, _Oil = 0;
bool gaming = 0;
bool command = 1;



const int N = 5;
int _Gained[num];
int offsetX = 0, offsetY = 0, position = 0;
int _time = 0;
int nitro;
int countdown = 0;
int _endgame = 0;

Text Score[N], Player;

float speed = 0.f, angle = 0.f;
float maxSpeed = 13.0f, bulletSpeed = 40.0f;
float acc = 0.2f, dec = 0.3f;
float turnSpeed = 0.03f;
float deltaTime = 0.0f;
float imedPosX, imedPosY;

Vector2f mousePos;
Vector2f AimDir;
Vector2f AimDirNor;
Vector2f PlayerCenter;

float R = 22;

std::vector <Bullet> buleet;
std::vector <Car> car;
std::vector <Oil> oil;
std::vector <Item> item;


RenderWindow app(VideoMode(1600, 900), "Racing Game", Style::Default);


float iPoints[num][2] = { 325, 450,
			  1335,450,
			  1355,2540,
			  1900,2540,
			  1967,1608,
			  2545,1608,
			  2440,3180,
			  325, 3230 };

View view(Vector2f(0.0f, 0.0f), Vector2f(1600.0f, 900.0f));