#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <ctime>
#include <time.h>
#include <stdio.h>
using namespace std;

int D_Of_C, OK, ane, xy, D_Of_C1, OK1, ane1, xy1, nowM, MoralValue;
int ict = 0, nowlevel = 99;
int bag[44] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0};
// 0抽奖券 1经验石R 2经验石SR 3经验石SSR 4经验石SSS 5经验石X
// 6技能书快快复苏 7技能书铁甲咒 8技能书昏昏倒地 9技能书神锋无影 10技能书咒立停 11技能书石化咒 12技能书恢复咒 13技能书召唤咒 14技能书遗忘咒 15技能书万弹齐发 16技能书钻心咒 17技能书夺魂咒 18技能书死亡咒
// 19生命药水 20防御药水 21攻击药水 22经验药水 23全幅药水
// 24猫狸子胡须 25媚娃头发 26马形水怪的鬃毛 27龙心腱 28雷鸟尾羽 29凤凰羽毛 30独角兽尾毛 31龙神经 32夜骐的尾羽
// 33桦木 34紫衫木 35冬青木 36山楂木柳条 37橡木 38械木 39山毛榉木 40栗木 41樱桃木 42桃花心木
// 43速度药水
string Material1name[9] = {"猫狸子胡须", "媚娃头发", "马形水怪的鬃毛", "龙心腱", "雷鸟尾羽", "凤凰羽毛", "独角兽尾毛", "龙神经", "夜骐的尾羽"};
string Material2name[10] = {"桦木", "紫衫木", "冬青木", "山楂木柳条", "橡木", "械木", "山毛榉木", "栗木", "樱桃木", "桃花心木"};
int health = 1000, maxhealth = 1000, attack = 250, defense = 10, experience = 0, camp, level = 1, amm = 1, f = 0, speed = 0;
long long money = 0;
string Nwand = "空手";
int LE1 = 1, LE2 = 1, Sl[13];
bool dead = false;
string wandname[100] = {"柳条魔杖", "胡桃魔杖", "鹅耳枥木魔杖", "柳条魔杖", "花心木魔杖", "冬青木魔杖", "紫杉木魔杖", "老魔杖"};
int wandpower[100] = {200, 500, 1100, 1300, 2400, 5000, 9000, 20000}, wand[100], wandi = 8, wandnamei = 8, wandpoweri = 8;
string name, password;
int choose()
{
	system("system");
	cout << "请选择您的阵营。" << endl;
	cout << "0, 哈利.HarryPotter" << endl;
	cout << "1, 伏地魔 LordVoldemort" << endl;
	cin >> camp;
	if (camp != 0 && camp != 1)
	{
		cout << "输入错误。";
		Sleep(250);
		choose();
	}
	else
	{
		if (MessageBox(0, TEXT("你确定？"), TEXT("请选择"), MB_OKCANCEL | MB_ICONINFORMATION) == IDOK)
			return 0;
		choose();
	}
	return 0;
}
int login()
{
	string DN, DPW;
	bool isn = false;
	cout << "请输入账号和密码" << endl;
	cout << "账号：";
	cin >> name;
	cout << "密码：";
	cin >> password;
	ifstream fin("data2.txt");
	while (fin >> DN)
	{
		if (DN == name)
		{
			fin >> DPW;
			if (DPW != password)
			{
				cout << "密码错误！" << endl;
				isn = true;
				system("system");
				login();
			}
			else
			{
				fin >> money >> attack >> defense >> health >> level >> experience >> LE1 >> LE2 >> camp >> maxhealth;
				fin >> D_Of_C >> OK >> ane >> xy >> D_Of_C1 >> OK1 >> ane1 >> xy1 >> nowM;
				fin >> bag[0] >> bag[1] >> bag[2] >> bag[3] >> bag[4] >> bag[5] >> bag[6] >> bag[7];
				fin >> bag[8] >> bag[9] >> bag[10] >> bag[11] >> bag[12] >> bag[13] >> bag[14] >> bag[15];
				fin >> bag[16] >> bag[17] >> bag[18] >> bag[19] >> bag[20] >> bag[21] >> bag[22] >> bag[23];
				fin >> bag[24] >> bag[25] >> bag[26] >> bag[27] >> bag[28] >> bag[29] >> bag[30] >> bag[31];
				fin >> bag[32] >> bag[33] >> bag[34] >> bag[35] >> bag[36] >> bag[37] >> bag[38] >> bag[39];
				fin >> bag[40] >> bag[41] >> bag[42] >> bag[43];
				fin >> Sl[0] >> Sl[1] >> Sl[2] >> Sl[3] >> Sl[4] >> Sl[5] >> Sl[6] >> Sl[7] >> Sl[8] >> Sl[9] >> Sl[10] >> Sl[11] >> Sl[12];
				for (int i = 0; i < 100; i++)
				{
					fin >> wandname[i];
					fin >> wandpower[i];
					fin >> wand[i];
				}
				fin >> Nwand >> amm >> f >> wandi >> wandnamei >> wandpoweri >> ict >> speed >> nowlevel;
				isn = true;
			}
		}
	}
	if (!isn)
	{
		cout << "无此用户！" << endl;
		login();
	}
	cout << "登入成功！" << endl;
	Sleep(1000);
	return 0;
}
int save()
{
	ofstream outfile("data2.txt", ios::binary | ios::app | ios::in | ios::out);
	outfile << name << " " << password << " " << money << " " << attack << " " << defense << " " << health << " " << level << " " << experience << " " << LE1 << " " << LE2 << " " << camp << " " << maxhealth << " ";
	outfile << D_Of_C << " " << OK << " " << ane << " " << xy << " " << D_Of_C1 << " " << OK1 << " " << ane1 << " " << xy1 << " " << nowM << " ";
	outfile << bag[0] << " " << bag[1] << " " << bag[2] << " " << bag[3] << " " << bag[4] << " " << bag[5] << " " << bag[6] << " " << bag[7] << " ";
	outfile << bag[8] << " " << bag[9] << " " << bag[10] << " " << bag[11] << " " << bag[12] << " " << bag[13] << " " << bag[14] << " " << bag[15] << " ";
	outfile << bag[16] << " " << bag[17] << " " << bag[18] << " " << bag[19] << " " << bag[20] << " " << bag[21] << " " << bag[22] << " " << bag[23] << " ";
	outfile << bag[24] << " " << bag[25] << " " << bag[26] << " " << bag[27] << " " << bag[28] << " " << bag[29] << " " << bag[30] << " " << bag[31] << " ";
	outfile << bag[32] << " " << bag[33] << " " << bag[34] << " " << bag[35] << " " << bag[36] << " " << bag[37] << " " << bag[38] << " " << bag[39] << " ";
	outfile << bag[40] << " " << bag[41] << " " << bag[42] << " " << bag[43] << " ";
	outfile << Sl[0] << " " << Sl[1] << " " << Sl[2] << " " << Sl[3] << " " << Sl[4] << " " << Sl[5] << " " << Sl[6] << " " << Sl[7] << " " << Sl[8] << " " << Sl[9] << " " << Sl[10] << " " << Sl[11] << " " << Sl[12] << " ";
	for (int i = 0; i < 100; i++)
	{
		outfile << wandname[i] << " ";
		outfile << wandpower[i] << " ";
		outfile << wand[i] << " ";
	}
	outfile << Nwand << " " << amm << " " << f << " " << wandi << " " << wandnamei << " " << wandpoweri << " " << ict << " " << speed << " " << nowlevel << endl;
	outfile.close();
	return 0;
}
int Reg()
{
	string DN, DPW;
	cout << "请输入账号和密码  " << endl;
	cout << "账号：";
	cin >> name;
	cout << endl
		 << "密码：";
	cin >> password;
	ifstream fin("data2.txt");
	while (fin >> DN)
	{
		if (DN == name)
		{
			cout << "用户名已被使用=====请重新起名";
			Reg();
		}
	}
	choose();
	return 0;
}
int monsterfight(string Hname, int hisH, int hisA, int hisD, int hisS, int hisSP)
{
	int mhealth = 10000, mdefense = 1000, mattack = 10000, mspeed = 500;
	int hfaint = 0;
	int mfaint = 0;
	dead = false;
	int ha = hisA;
	while (1)
	{
		if (hfaint > 0)
			hfaint -= 1;
		if (mfaint > 0)
		{
			if (rand() % 3 == 0)
			{
				mfaint = 0;
				cout << "石怪使用技能咒立停，停止了魔咒！" << endl;
			}
			else
				mfaint -= 1;
		}
		if (mfaint <= 0)
		{
			if (rand() % 3)
			{
				cout << "石怪使用技能快快复苏 生命增加200" << endl;
				mhealth += 200;
			}
			if (rand() % 3)
			{
				cout << "石怪使用技能铁甲护身 生命增加100 防御增加50" << endl;
				mhealth += 100;
				mdefense += 50;
			}
			if (rand() % 3)
			{
				cout << "石怪使用技能神锋无影 攻击增加200 对方扣血200滴" << endl;
				hisH -= 200;
				mattack += 200;
			}
			Sleep(1000);
			int ran = rand() % 40 - 20;
			if (rand() % 10000 > hisSP)
			{
				if (attack + ran > hisD)
				{
					cout << "石怪发起进攻 " << Hname << "扣血" << mattack - hisD + ran << "滴 剩余" << hisH - (mattack - hisD + ran) << "滴" << endl;
					hisH -= mattack - hisD + ran;
				}
				else
					cout << "石怪发起进攻 " << Hname << "扣血0滴 剩余" << hisH << "滴" << endl;
			}
			else
			{
				if (rand() % 2)
					cout << "石怪一脚踹了过去，但没有踢中" << endl;
				else
				{
					cout << "石怪一脚踹了过去，但只擦着了腰" << endl;
					if ((mattack / 3) + ran > hisD)
					{
						cout << Hname << "扣血" << (mattack / 3) + ran - hisD << "滴 剩余" << hisH - ((mattack / 3) + ran - hisD) << "滴" << endl;
						hisH -= (mattack / 3) + ran - hisD;
					}
					else
						cout << Hname << "扣血0滴 剩余" << hisH << "滴" << endl;
				}
			}
		}
		Sleep(1000);
		if (hisH <= 0)
		{
			if (hisS == 20 && rand() % 3 == 0)
			{
				cout << "对方发动技能：恢复如初 满血复活" << endl;
				hisH = ha;
				Sleep(1000);
			}
			else
			{
				cout << "对方死亡" << endl;
				return 0;
			}
		}
		if (hfaint <= 0)
		{
			if (hisS != 0)
			{
				if (rand() % 3 == 0)
				{
					if (hisS == 14)
					{
						cout << "对方发动技能：快快复苏  生命加200" << endl;
						hisH += 200;
					}
					if (hisS == 15)
					{
						cout << "对方发动技能：盔甲护身  生命加50 防御增加50" << endl;
						hisH += 50;
						hisD += 50;
					}
					if (hisS == 17)
					{
						cout << "对方发动技能神锋无影 攻击增加200 扣血200滴" << endl;
						health -= 200;
						hisA += 200;
					}
				}
				Sleep(1000);
			}
			int ran = rand() % 40 - 20;
			if (rand() % 10000 > mspeed)
			{
				if (hisA + ran > defense)
				{
					cout << Hname << "发起进攻 "
						 << "石怪扣血" << hisA - defense + ran << "滴 剩余" << mhealth - (hisA - defense + ran) << "滴" << endl;
					mhealth -= hisA - defense + ran;
				}
				else
					cout << Hname << "发起进攻 "
						 << "石怪扣血0滴 剩余" << mhealth << "滴" << endl;
			}
			else
			{
				if (rand() % 2)
					cout << Hname << "一脚踹了过来，但没有踢中" << endl;
				else
				{
					cout << "对方一脚踹了过来，但只擦着了石怪的腰" << endl;
					if ((hisA / 3) + ran > hisD)
					{
						cout << "石怪扣血" << (hisA / 3) + ran - defense << "滴 剩余" << mhealth - ((hisA / 3) + ran - defense) << "滴" << endl;
						mhealth -= ((hisA / 3) + ran - defense);
					}
					else
						cout << "石怪扣血0滴 剩余" << mhealth << "滴" << endl;
				}
			}
			Sleep(1000);
			if (mhealth <= 0)
			{
				cout << "石怪死亡" << endl;
				return hisH;
			}
		}
	}
	return 0;
}
int fight1(string Hname, int hisH, int hisA, int hisD, int hisS, int hisSP)
{
	int hfaint = 0, hhurt = 0, hbeat = 0;
	int mfaint = 0, mhurt = 0;
	dead = false;
	int ha = hisA;
	int his = hisA + hisD + hisH;
	while (1)
	{
		if (hfaint > 0)
		{
			if (rand() % 3 == 0)
			{
				cout << "对方使用技能：咒立停！停止了魔咒" << endl;
				hfaint = 1;
			}
			hfaint -= 1;
		}
		if (hbeat == 1)
		{
			if (rand() % 10 == 0)
			{
				cout << "对方一躲，躲过了你的石头" << endl;
				hbeat = 0;
			}
			else
			{
				cout << "对方躲闪不急，石头正好撞在他的鼻子上 扣血50滴" << endl;
				hisH -= 50;
			}
		}
		if (mfaint > 0)
		{
			if (Sl[6])
				mfaint = 0;
			else
				mfaint -= 1;
		}
		if (mhurt > 0)
		{
			if (Sl[6])
				mhurt = 0;
			else
				mhurt -= 1;
			cout << "你的心像被一把刀刺穿了一样 扣血200滴" << endl;
			health -= 200;
		}
		if (mfaint <= 0)
		{
			if (rand() % 3 && Sl[0])
			{
				cout << "你使用技能快快复苏 生命增加200" << endl;
				health += 200;
			}
			if (rand() % 3 && Sl[1])
			{
				cout << "你使用技能铁甲护身 生命增加100 防御增加50" << endl;
				health += 100;
				defense += 50;
			}
			if (rand() % 3 && Sl[2])
			{
				cout << "你使用技能昏昏倒地 " << Hname << "一回合之内不能攻击" << endl;
				hfaint += 1;
			}
			if (rand() % 3 && Sl[3])
			{
				cout << "你使用技能神锋无影 攻击增加200 扣血200滴" << endl;
				hisH -= 200;
				attack += 200;
			}
			if (rand() % 3 && Sl[5])
			{
				if (rand() % 10)
				{
					cout << "你使用技能统统石化 " << Hname << "二回合之内不能攻击" << endl;
					hfaint += 2;
				}
				else
				{
					cout << "你使用技能统统石化 " << Hname << "十回合之内不能攻击" << endl;
					hfaint += 10;
				}
			}
			if (rand() % 4 == 0 && Sl[7])
			{
				cout << "你使用技能召唤咒！召唤出石怪跟" << Hname << "战斗" << endl;
				hisH = monsterfight(Hname, hisH, hisA, hisD, hisS, hisSP);
				if (hisH < 1)
					return 0;
				if (Sl[0])
				{
					cout << "在对方和石怪的战斗中，你已经恢复了2000生命" << endl;
					if (maxhealth < health + 2000)
						health = maxhealth;
					else
						health += 2000;
				}
			}
			if (rand() % 4 == 0 && Sl[8])
			{
				cout << "你使用技能召唤咒！召唤出石怪跟" << Hname << "战斗" << endl;
			}
			if (rand() % 3 && Sl[9])
			{
				cout << "你使用技能万弹齐发！变出几十块石头" << endl;
				hbeat = 1;
			}
			if (rand() % 3 && Sl[10])
			{
				cout << "你使用技能钻心咒！对方将疼痛5回合" << endl;
				hhurt += 5;
			}
			if (rand() % 3 && Sl[11])
			{
				cout << "魂魄出窍！你使用夺魂咒，企图让" << Hname << "自己攻击自己！" << endl;
				Sleep((rand() % 1000) + 1000);
				cout << Hname << "被你控制了，开始攻击自己" << endl;
				Sleep(700);
				int ran = rand() % 40 - 20;
				if (hisA + ran > hisD)
				{
					cout << "对方发起进攻 自己扣血" << hisH - hisD + ran << "滴 剩余" << hisH - (hisA - hisD + ran) << "滴" << endl;
					hisH -= hisA - hisD + ran;
				}
				else
					cout << "对方发起进攻 自己扣血0滴 剩余" << hisH << "滴" << endl;
			}
			if (rand() % 2 && Sl[12])
			{
				cout << "你使用技能阿瓦达索命 " << Hname << "扣血" << hisH - hisH / 4 << "滴" << endl;
				hisH /= 4;
			}
			Sleep(1000);
			int ran = rand() % 40 - 20;
			if (rand() % 10000 > hisSP)
			{
				if (attack + ran > hisD)
				{
					cout << "你发起进攻 " << Hname << "扣血" << attack - hisD + ran << "滴 剩余" << hisH - (attack - hisD + ran) << "滴" << endl;
					hisH -= attack - hisD + ran;
				}
				else
					cout << "你发起进攻 " << Hname << "扣血0滴 剩余" << hisH << "滴" << endl;
			}
			else
			{
				if (rand() % 2)
					cout << "你一脚踹了过去，但没有踢中" << endl;
				else
				{
					cout << "你一脚踹了过去，但只擦着了腰" << endl;
					if ((attack / 3) + ran > hisD)
					{
						cout << Hname << "扣血" << (attack / 3) + ran - hisD << "滴 剩余" << hisH - ((attack / 3) + ran - hisD) << "滴" << endl;
						hisH -= (attack / 3) + ran - hisD;
					}
					else
						cout << Hname << "扣血0滴 剩余" << hisH << "滴" << endl;
				}
			}
		}
		Sleep(700);
		if (hhurt > 0)
		{
			hhurt -= 1;
			cout << "对方因中了你的钻心咒，正捂着心大叫呢 扣血200滴" << endl;
			hisH -= 200;
		}
		if (hisH <= 0)
		{
			if (hisS == 20 && rand() % 3 == 0)
			{
				cout << "对方发动技能：恢复如初 满血复活" << endl;
				hisH = ha;
				Sleep(1000);
			}
			else
			{
				cout << "对方死亡\n获得" << (his / 30) << "经验" << endl;
				experience += (his / 30);
				if (ane == 3)
					D_Of_C++;
				if (ane1 == 3)
					D_Of_C1++;
				return 0;
			}
		}
		if (hfaint <= 0)
		{
			if (rand() % 3 == 0)
			{
				if (hisS == 14)
				{
					cout << "对方发动技能：快快复苏  生命加200" << endl;
					hisH += 200;
				}
				if (hisS == 15)
				{
					cout << "对方发动技能：盔甲护身  生命加50 防御增加50" << endl;
					hisH += 50;
					hisD += 50;
				}
				if (hisS == 17)
				{
					cout << "对方发动技能神锋无影 攻击增加200 扣血200滴" << endl;
					health -= 200;
					hisA += 200;
				}
				Sleep(1000);
			}
			int ran = rand() % 40 - 20;
			if (rand() % 10000 > speed)
			{
				if (hisA + ran > defense)
				{
					cout << Hname << "发起进攻 "
						 << "你扣血" << hisA - defense + ran << "滴 剩余" << health - (hisA - defense + ran) << "滴" << endl;
					health -= hisA - defense + ran;
				}
				else
					cout << Hname << "发起进攻 "
						 << "你扣血0滴 剩余" << health << "滴" << endl;
			}
			else
			{
				if (rand() % 2)
					cout << Hname << "一脚踹了过来，但没有踢中" << endl;
				else
				{
					cout << "对方一脚踹了过来，但只擦着了你的腰" << endl;
					if ((hisA / 3) + ran > hisD)
					{
						cout << "你扣血" << (hisA / 3) + ran - defense << "滴 剩余" << health - ((hisA / 3) + ran - defense) << "滴" << endl;
						health -= ((hisA / 3) + ran - defense);
					}
					else
						cout << "你扣血0滴 剩余" << health << "滴" << endl;
				}
			}
			Sleep(700);
			if (health <= 0)
			{
				if (Sl[6] && rand() % 2)
				{
					cout << "你发动技能：恢复如初 满血复活" << endl;
					health = maxhealth;
					Sleep(1000);
				}
				else
				{
					cout << "你死亡";
					health = 20;
					dead = true;
					return 0;
				}
			}
		}
	}
	return 0;
}
int fight2(string Hname, int hisH, int hisA, int hisD, int hisS, int hisSP)
{
	int hfaint = 0, hhurt = 0, hbeat = 0;
	int mfaint = 0, mhurt = 0;
	dead = false;
	int ha = hisA;
	int his = hisA + hisD + hisH;
	while (1)
	{
		if (hfaint > 0)
		{
			if (rand() % 3 == 0)
			{
				cout << "对方使用技能：咒立停！停止了魔咒";
				hfaint = 1;
			}
			hfaint -= 1;
		}
		if (hbeat == 1)
		{
			if (rand() % 10 == 0)
			{
				cout << "对方一躲，躲过了你的石头" << endl;
				hbeat = 0;
			}
			else
			{
				cout << "对方躲闪不急，石头正好撞在他的鼻子上 扣血50滴" << endl;
				hisH -= 50;
			}
		}
		if (mfaint > 0)
		{
			if (Sl[6])
				mfaint = 0;
			else
				mfaint -= 1;
		}
		if (mhurt > 0)
		{
			if (Sl[6])
				mhurt = 0;
			else
				mhurt -= 1;
			cout << "你的心像被一把刀刺穿了一样 扣血200滴" << endl;
			health -= 200;
		}
		if (mfaint <= 0)
		{
			if (rand() % 3 && Sl[0])
			{
				cout << "你使用技能快快复苏 生命增加200" << endl;
				health += 200;
			}
			if (rand() % 3 && Sl[1])
			{
				cout << "你使用技能铁甲护身 生命增加100 防御增加50" << endl;
				health += 100;
				defense += 50;
			}
			if (rand() % 3 && Sl[2])
			{
				cout << "你使用技能昏昏倒地 " << Hname << "一回合之内不能攻击" << endl;
				hfaint += 1;
			}
			if (rand() % 3 && Sl[3])
			{
				cout << "你使用技能神锋无影 攻击增加200 扣血200滴" << endl;
				hisH -= 200;
				attack += 200;
			}
			if (rand() % 3 && Sl[5])
			{
				if (rand() % 10)
				{
					cout << "你使用技能统统石化 " << Hname << "二回合之内不能攻击" << endl;
					hfaint += 2;
				}
				else
				{
					cout << "你使用技能统统石化 " << Hname << "十回合之内不能攻击" << endl;
					hfaint += 10;
				}
			}
			if (rand() % 4 == 0 && Sl[7])
			{
				cout << "你使用技能召唤咒！召唤出石怪跟" << Hname << "战斗" << endl;
				hisH = monsterfight(Hname, hisH, hisA, hisD, hisS, hisSP);
				if (hisH < 1)
					return 0;
				if (Sl[0])
				{
					cout << "在对方和石怪的战斗中，你已经恢复了2000生命" << endl;
					if (maxhealth < health + 2000)
						health = maxhealth;
					else
						health += 2000;
				}
				Sleep(1000);
			}
			if (rand() % 4 == 0 && Sl[8])
			{
				cout << "你使用技能召唤咒！召唤出石怪跟" << Hname << "战斗" << endl;
			}
			if (rand() % 3 && Sl[9])
			{
				cout << "你使用技能万弹齐发！变出几十块石头" << endl;
				hbeat = 1;
			}
			if (rand() % 3 && Sl[10])
			{
				cout << "你使用技能钻心咒！对方将疼痛5回合" << endl;
				hhurt += 5;
			}
			if (rand() % 3 && Sl[11])
			{
				cout << "魂魄出窍！你使用夺魂咒，企图让" << Hname << "自己攻击自己！" << endl;
				Sleep((rand() % 1000) + 1000);
				cout << Hname << "被你控制了，开始攻击自己" << endl;
				Sleep(700);
				int ran = rand() % 40 - 20;
				if (hisA + ran > hisD)
				{
					cout << "对方发起进攻 自己扣血" << hisH - hisD + ran << "滴 剩余" << hisH - (hisA - hisD + ran) << "滴" << endl;
					hisH -= hisA - hisD + ran;
				}
				else
					cout << "对方发起进攻 自己扣血0滴 剩余" << hisH << "滴" << endl;
			}
			if (rand() % 2 && Sl[12])
			{
				cout << "你使用技能阿瓦达索命 " << Hname << "扣血" << hisH - hisH / 4 << "滴" << endl;
				hisH /= 4;
			}
			Sleep(1000);
			int ran = rand() % 40 - 20;
			if (rand() % 10000 > hisSP)
			{
				if (attack + ran > hisD)
				{
					cout << "你发起进攻 " << Hname << "扣血" << attack - hisD + ran << "滴 剩余" << hisH - (attack - hisD + ran) << "滴" << endl;
					hisH -= attack - hisD + ran;
				}
				else
					cout << "你发起进攻 " << Hname << "扣血0滴 剩余" << hisH << "滴" << endl;
			}
			else
			{
				if (rand() % 2)
					cout << "你一脚踹了过去，但没有踢中" << endl;
				else
				{
					cout << "你一脚踹了过去，但只擦着了腰" << endl;
					if ((attack / 3) + ran > hisD)
					{
						cout << Hname << "扣血" << (attack / 3) + ran - hisD << "滴 剩余" << hisH - ((attack / 3) + ran - hisD) << "滴" << endl;
						hisH -= (attack / 3) + ran - hisD;
					}
					else
						cout << Hname << "扣血0滴 剩余" << hisH << "滴" << endl;
				}
			}
		}
		Sleep(700);
		if (hhurt > 0)
		{
			hhurt -= 1;
			cout << "对方因中了你的钻心咒，正捂着心大叫呢 扣血200滴" << endl;
			hisH -= 200;
		}
		if (hisH <= 0)
		{
			if (hisS == 20 && rand() % 3 == 0)
			{
				cout << "对方发动技能：恢复如初 满血复活" << endl;
				hisH = ha;
				Sleep(1000);
			}
			else
			{
				cout << "对方死亡\n获得" << (his / 200) << "金币" << endl;
				money += (his / 200);
				if (ane == 3)
					D_Of_C++;
				if (ane1 == 3)
					D_Of_C1++;
				return 0;
			}
		}
		if (hfaint <= 0)
		{
			if (rand() % 3 == 0)
			{
				if (hisS == 14)
				{
					cout << "对方发动技能：快快复苏  生命加200" << endl;
					hisH += 200;
				}
				if (hisS == 15)
				{
					cout << "对方发动技能：盔甲护身  生命加50 防御增加50" << endl;
					hisH += 50;
					hisD += 50;
				}
				if (hisS == 17)
				{
					cout << "对方发动技能神锋无影 攻击增加200 扣血200滴" << endl;
					health -= 200;
					hisA += 200;
				}
				Sleep(1000);
			}
			int ran = rand() % 40 - 20;
			if (rand() % 10000 > speed)
			{
				if (hisA + ran > defense)
				{
					cout << Hname << "发起进攻 "
						 << "你扣血" << hisA - defense + ran << "滴 剩余" << health - (hisA - defense + ran) << "滴" << endl;
					health -= hisA - defense + ran;
				}
				else
					cout << Hname << "发起进攻 "
						 << "你扣血0滴 剩余" << health << "滴" << endl;
			}
			else
			{
				if (rand() % 2)
					cout << Hname << "一脚踹了过来，但没有踢中" << endl;
				else
				{
					cout << "对方一脚踹了过来，但只擦着了你的腰" << endl;
					if ((hisA / 3) + ran > hisD)
					{
						cout << "你扣血" << (hisA / 3) + ran - defense << "滴 剩余" << health - ((hisA / 3) + ran - defense) << "滴" << endl;
						health -= ((hisA / 3) + ran - defense);
					}
					else
						cout << "你扣血0滴 剩余" << health << "滴" << endl;
				}
			}
			Sleep(700);
			if (health <= 0)
			{
				if (Sl[6] && rand() % 2)
				{
					cout << "你发动技能：恢复如初 满血复活" << endl;
					health = maxhealth;
					Sleep(1000);
				}
				else
				{
					cout << "你死亡";
					health = 20;
					dead = true;
					return 0;
				}
			}
		}
	}
	return 0;
}
int fight(string Hname, int hisH, int hisA, int hisD, int hisS, int hisSP)
{
	int hfaint = 0, hhurt = 0, hbeat = 0;
	int mfaint = 0, mhurt = 0;
	dead = false;
	int ha = hisA;
	int his = hisA + hisD + hisH;
	while (1)
	{
		if (hfaint > 0)
		{
			if (rand() % 3 == 0)
			{
				cout << "对方使用技能：咒立停！停止了魔咒" << endl;
				hfaint = 0;
			}
			else
				hfaint -= 1;
		}
		if (hbeat == 1)
		{
			if (rand() % 10 == 0)
			{
				cout << "对方一躲，躲过了你的石头" << endl;
				hbeat = 0;
			}
			else
			{
				cout << "对方躲闪不急，石头正好撞在他的鼻子上 扣血50滴" << endl;
				hisH -= 50;
			}
		}
		if (mfaint > 0)
		{
			if (Sl[6])
				mfaint = 0;
			else
				mfaint -= 1;
		}
		if (mhurt > 0)
		{
			if (Sl[6])
				mhurt = 0;
			else
				mhurt -= 1;
			cout << "你的心像被一把刀刺穿了一样 扣血200滴" << endl;
			health -= 200;
		}
		if (mfaint <= 0)
		{
			if (rand() % 3 && Sl[0])
			{
				cout << "你使用技能快快复苏 生命增加200" << endl;
				health += 200;
			}
			if (rand() % 3 && Sl[1])
			{
				cout << "你使用技能铁甲护身 生命增加100 防御增加50" << endl;
				health += 100;
				defense += 50;
			}
			if (rand() % 3 && Sl[2])
			{
				cout << "你使用技能昏昏倒地 " << Hname << "一回合之内不能攻击" << endl;
				hfaint += 1;
			}
			if (rand() % 3 && Sl[3])
			{
				cout << "你使用技能神锋无影 攻击增加200 扣血200滴" << endl;
				hisH -= 200;
				attack += 200;
			}
			if (rand() % 3 && Sl[5])
			{
				if (rand() % 10)
				{
					cout << "你使用技能统统石化 " << Hname << "二回合之内不能攻击" << endl;
					hfaint += 2;
				}
				else
				{
					cout << "你使用技能统统石化 " << Hname << "十回合之内不能攻击" << endl;
					hfaint += 10;
				}
			}
			if (rand() % 4 == 0 && Sl[7])
			{
				cout << "你使用技能召唤咒！召唤出石怪跟" << Hname << "战斗" << endl;
				hisH = monsterfight(Hname, hisH, hisA, hisD, hisS, hisSP);
				if (hisH < 1)
					return 0;
				if (Sl[0])
				{
					cout << "在对方和石怪的战斗中，你已经恢复了2000生命" << endl;
					if (maxhealth < health + 2000)
						health = maxhealth;
					else
						health += 2000;
				}
			}
			if (rand() % 4 == 0 && Sl[8])
			{
				cout << "你使用技能召唤咒！召唤出石怪跟" << Hname << "战斗" << endl;
			}
			if (rand() % 3 && Sl[9])
			{
				cout << "你使用技能万弹齐发！变出几十块石头" << endl;
				hbeat = 1;
			}
			if (rand() % 3 && Sl[10])
			{
				cout << "你使用技能钻心咒！对方将疼痛5回合" << endl;
				hhurt += 5;
			}
			if (rand() % 3 && Sl[11])
			{
				cout << "魂魄出窍！你使用夺魂咒，企图让" << Hname << "自己攻击自己！" << endl;
				Sleep((rand() % 1000) + 1000);
				cout << Hname << "被你控制了，开始攻击自己" << endl;
				Sleep(700);
				int ran = rand() % 40 - 20;
				if (hisA + ran > hisD)
				{
					cout << "对方发起进攻 自己扣血" << hisH - hisD + ran << "滴 剩余" << hisH - (hisA - hisD + ran) << "滴" << endl;
					hisH -= hisA - hisD + ran;
				}
				else
					cout << "对方发起进攻 自己扣血0滴 剩余" << hisH << "滴" << endl;
			}
			if (rand() % 2 && Sl[12])
			{
				cout << "你使用技能阿瓦达索命 " << Hname << "扣血" << hisH - hisH / 4 << "滴" << endl;
				hisH /= 4;
			}
			Sleep(1000);
			int ran = rand() % 40 - 20;
			if (rand() % 10000 > hisSP)
			{
				if (attack + ran > hisD)
				{
					cout << "你发起进攻 " << Hname << "扣血" << attack - hisD + ran << "滴 剩余" << hisH - (attack - hisD + ran) << "滴" << endl;
					hisH -= attack - hisD + ran;
				}
				else
					cout << "你发起进攻 " << Hname << "扣血0滴 剩余" << hisH << "滴" << endl;
			}
			else
			{
				if (rand() % 2)
					cout << "你一脚踹了过去，但没有踢中" << endl;
				else
				{
					cout << "你一脚踹了过去，但只擦着了腰" << endl;
					if ((attack / 3) + ran > hisD)
					{
						cout << Hname << "扣血" << (attack / 3) + ran - hisD << "滴 剩余" << hisH - ((attack / 3) + ran - hisD) << "滴" << endl;
						hisH -= (attack / 3) + ran - hisD;
					}
					else
						cout << Hname << "扣血0滴 剩余" << hisH << "滴" << endl;
				}
			}
		}
		Sleep(700);
		if (hhurt > 0)
		{
			hhurt -= 1;
			cout << "对方因中了你的钻心咒，正捂着心大叫呢 扣血200滴" << endl;
			hisH -= 200;
		}
		if (hisH <= 0)
		{
			if (hisS == 20 && rand() % 3 == 0)
			{
				cout << "对方发动技能：恢复如初 满血复活" << endl;
				hisH = ha;
				Sleep(1000);
			}
			else
			{
				cout << "对方死亡\n获得" << his / 30 << "元" << endl;
				money += his / 30;
				experience += (his / 30) * 10;
				if (ane == 3)
					D_Of_C++;
				if (ane1 == 3)
					D_Of_C1++;
				return 0;
			}
		}
		if (hfaint <= 0)
		{
			if (rand() % 3 == 0)
			{
				if (hisS == 14)
				{
					cout << "对方发动技能：快快复苏  生命加200" << endl;
					hisH += 200;
				}
				if (hisS == 15)
				{
					cout << "对方发动技能：盔甲护身  生命加50 防御增加50" << endl;
					hisH += 50;
					hisD += 50;
				}
				if (hisS == 17)
				{
					cout << "对方发动技能神锋无影 攻击增加200 扣血200滴" << endl;
					health -= 200;
					hisA += 200;
				}
				Sleep(1000);
			}
			int ran = rand() % 40 - 20;
			if (rand() % 10000 > speed)
			{
				if (hisA + ran > defense)
				{
					cout << Hname << "发起进攻 "
						 << "你扣血" << hisA - defense + ran << "滴 剩余" << health - (hisA - defense + ran) << "滴" << endl;
					health -= hisA - defense + ran;
				}
				else
					cout << Hname << "发起进攻 "
						 << "你扣血0滴 剩余" << health << "滴" << endl;
			}
			else
			{
				if (rand() % 2)
					cout << Hname << "一脚踹了过来，但没有踢中" << endl;
				else
				{
					cout << "对方一脚踹了过来，但只擦着了你的腰" << endl;
					if ((hisA / 3) + ran > hisD)
					{
						cout << "你扣血" << (hisA / 3) + ran - defense << "滴 剩余" << health - ((hisA / 3) + ran - defense) << "滴" << endl;
						health -= ((hisA / 3) + ran - defense);
					}
					else
						cout << "你扣血0滴 剩余" << health << "滴" << endl;
				}
			}
			Sleep(700);
			if (health <= 0)
			{
				if (Sl[6] && rand() % 2)
				{
					cout << "你发动技能：恢复如初 满血复活" << endl;
					health = maxhealth;
					Sleep(1000);
				}
				else
				{
					cout << "你死亡" << endl;
					health = 20;
					dead = true;
					return 0;
				}
			}
		}
	}
	return 0;
}
int street()
{
	switch (rand() % 6)
	{
	case 0:
		if (camp)
		{
			int f;
			cout << "你遇到了一个路人" << endl;
			cout << "1进攻/2逃跑" << endl;
			cin >> f;
			if (f == 1)
			{
				fight("路人", 500, 110, 0, 14, 1000);
				if (!dead && rand() % 2)
				{
					if (rand() % 4 == 0)
					{
						cout << "获得一瓶经验药水" << endl;
						bag[22] += 1;
					}
					else if (rand() % 4 == 1)
					{
						cout << "获得一瓶攻击药水" << endl;
						bag[21] += 1;
					}
					else if (rand() % 4 == 2)
					{
						cout << "获得一瓶生命药水" << endl;
						bag[19] += 1;
					}
					else
					{
						cout << "获得一瓶防御药水" << endl;
						bag[20] += 1;
					}
				}
			}
		}
		else
		{
			int f;
			cout << "你遇到了一个小混混" << endl;
			cout << "1进攻/2逃跑" << endl;
			cin >> f;
			if (f == 1)
			{
				fight("小混混", 500, 110, 0, 15, 1000);
				if (!dead && rand() % 2)
				{
					if (rand() % 4 == 0)
					{
						cout << "获得一瓶经验药水" << endl;
						bag[22] += 1;
					}
					else if (rand() % 4 == 1)
					{
						cout << "获得一瓶攻击药水" << endl;
						bag[21] += 1;
					}
					else if (rand() % 4 == 2)
					{
						cout << "获得一瓶生命药水" << endl;
						bag[19] += 1;
					}
					else
					{
						cout << "获得一瓶防御药水" << endl;
						bag[20] += 1;
					}
				}
			}
		}
		break;
	case 1:
		if (camp)
		{
			int f;
			cout << "你遇到了一个警察" << endl;
			cout << "1进攻/2逃跑" << endl;
			cin >> f;
			if (f == 1)
			{
				fight("警察", 2000, 500, 15, 15, 1000);
				if (!dead && rand() % 3 != 0)
				{
					if (rand() % 5 == 0)
					{
						cout << "获得两瓶经验药水" << endl;
						bag[22] += 2;
					}
					else if (rand() % 5 == 1)
					{
						cout << "获得两瓶攻击药水" << endl;
						bag[21] += 2;
					}
					else if (rand() % 5 == 2)
					{
						cout << "获得两瓶生命药水" << endl;
						bag[19] += 2;
					}
					else if (rand() % 5 == 3)
					{
						cout << "获得一瓶全幅药水" << endl;
						bag[23] += 1;
					}
					else
					{
						cout << "获得两瓶防御药水" << endl;
						bag[20] += 2;
					}
				}
			}
		}
		else
		{
			int f;
			cout << "你遇到了一个小食死徒" << endl;
			cout << "1进攻/2逃跑" << endl;
			cin >> f;
			if (f == 1)
			{
				fight("食死徒", 2000, 500, 15, 15, 1000);
				if (!dead && rand() % 3 != 0)
				{
					if (rand() % 5 == 0)
					{
						cout << "获得两瓶经验药水" << endl;
						bag[22] += 2;
					}
					else if (rand() % 5 == 1)
					{
						cout << "获得两瓶攻击药水" << endl;
						bag[21] += 2;
					}
					else if (rand() % 5 == 2)
					{
						cout << "获得两瓶生命药水" << endl;
						bag[19] += 2;
					}
					else if (rand() % 5 == 3)
					{
						cout << "获得一瓶全幅药水" << endl;
						bag[23] += 1;
					}
					else
					{
						cout << "获得两瓶防御药水" << endl;
						bag[20] += 2;
					}
				}
			}
		}
		break;
	case 2:
		if (camp)
		{
			int f;
			cout << "你遇到了一个凤凰社成员" << endl;
			cout << "1进攻/2逃跑" << endl;
			cin >> f;
			if (f == 1)
			{
				fight("凤凰社成员", 5000, 700, 50, 16, 1500);
				if (!dead && rand() % 4 != 0)
				{
					if (rand() % 5 == 0)
					{
						cout << "获得三瓶经验药水" << endl;
						bag[22] += 3;
					}
					else if (rand() % 5 == 1)
					{
						cout << "获得三瓶攻击药水" << endl;
						bag[21] += 3;
					}
					else if (rand() % 5 == 2)
					{
						cout << "获得三瓶生命药水" << endl;
						bag[19] += 3;
					}
					else if (rand() % 5 == 3)
					{
						cout << "获得两瓶全幅药水" << endl;
						bag[23] += 2;
					}
					else
					{
						cout << "获得三瓶防御药水" << endl;
						bag[20] += 3;
					}
				}
			}
		}
		else
		{
			int f;
			cout << "你遇到了一个真食死徒" << endl;
			cout << "1进攻/2逃跑" << endl;
			cin >> f;
			if (f == 1)
			{
				fight("食死徒", 5000, 700, 50, 15, 1500);
				if (!dead && rand() % 4 != 0)
				{
					if (rand() % 5 == 0)
					{
						cout << "获得三瓶经验药水" << endl;
						bag[22] += 3;
					}
					else if (rand() % 5 == 1)
					{
						cout << "获得三瓶攻击药水" << endl;
						bag[21] += 3;
					}
					else if (rand() % 5 == 2)
					{
						cout << "获得三瓶生命药水" << endl;
						bag[19] += 3;
					}
					else if (rand() % 5 == 3)
					{
						cout << "获得两瓶全幅药水" << endl;
						bag[23] += 2;
					}
					else
					{
						cout << "获得三瓶防御药水" << endl;
						bag[20] += 3;
					}
				}
			}
		}
		break;
	case 3:
		if (camp)
		{
			int f;
			cout << "你遇到了一个傲罗·穆迪" << endl;
			cout << "1进攻/2逃跑" << endl;
			cin >> f;
			if (f == 1)
			{
				fight("穆迪", 10000, 1200, 250, 17, 2000);
				if (!dead)
				{
					if (rand() % 3)
					{
						if (rand() % 2)
						{
							cout << "获得技能书神锋无影" << endl;
							bag[9]++;
						}
						else
						{
							cout << "获得技能书快快复苏" << endl;
							bag[6]++;
						}
					}
					if (rand() % 4)
					{
						if (rand() % 5 == 0)
						{
							cout << "获得四瓶经验药水" << endl;
							bag[22] += 4;
						}
						else if (rand() % 5 == 1)
						{
							cout << "获得四瓶攻击药水" << endl;
							bag[21] += 4;
						}
						else if (rand() % 5 == 2)
						{
							cout << "获得四瓶生命药水" << endl;
							bag[19] += 4;
						}
						else if (rand() % 5 == 3)
						{
							cout << "获得三瓶全幅药水" << endl;
							bag[23] += 3;
						}
						else
						{
							cout << "获得四瓶防御药水" << endl;
							bag[20] += 4;
						}
					}
				}
			}
		}
		else
		{
			int f;
			cout << "你遇到了卢修斯·马尔福" << endl;
			cout << "1进攻/2逃跑" << endl;
			cin >> f;
			if (f == 1)
			{
				fight("马尔福", 10000, 1200, 250, 17, 2000);
				if (!dead)
				{
					if (rand() % 3)
					{
						if (rand() % 2)
						{
							cout << "获得技能书神锋无影" << endl;
							bag[9]++;
						}
						else
						{
							cout << "获得技能书快快复苏" << endl;
							bag[6]++;
						}
					}
					if (rand() % 4)
					{
						if (rand() % 5 == 0)
						{
							cout << "获得四瓶经验药水" << endl;
							bag[22] += 4;
						}
						else if (rand() % 5 == 1)
						{
							cout << "获得四瓶攻击药水" << endl;
							bag[21] += 4;
						}
						else if (rand() % 5 == 2)
						{
							cout << "获得四瓶生命药水" << endl;
							bag[19] += 4;
						}
						else if (rand() % 5 == 3)
						{
							cout << "获得三瓶全幅药水" << endl;
							bag[23] += 3;
						}
						else
						{
							cout << "获得四瓶防御药水" << endl;
							bag[20] += 4;
						}
					}
				}
			}
		}
		if (!dead)
			if (ane1 == 2)
				D_Of_C1++;
		break;
	case 4:
		if (camp)
		{
			int f;
			cout << "你遇到了卢平" << endl;
			cout << "1进攻/2逃跑" << endl;
			cin >> f;
			if (f == 1)
			{
				fight("卢平", 100000, 12000, 2500, 17, 4000);
				if (!dead)
				{
					if (rand() % 3)
					{
						if (rand() % 2)
						{
							cout << "获得技能书恢复如初" << endl;
							bag[12]++;
						}
						else
						{
							cout << "获得技能书阿瓦达索命" << endl;
							bag[18]++;
						}
					}
					if (rand() % 5)
					{
						if (rand() % 5 == 0)
						{
							cout << "获得四瓶经验药水" << endl;
							bag[22] += 4;
						}
						else if (rand() % 5 == 1)
						{
							cout << "获得四瓶攻击药水" << endl;
							bag[21] += 4;
						}
						else if (rand() % 5 == 2)
						{
							cout << "获得四瓶生命药水" << endl;
							bag[19] += 4;
						}
						else if (rand() % 5 == 3)
						{
							cout << "获得三瓶全幅药水" << endl;
							bag[23] += 3;
						}
						else
						{
							cout << "获得四瓶防御药水" << endl;
							bag[20] += 4;
						}
					}
				}
			}
		}
		else
		{
			int f;
			cout << "你遇到了食死徒·卡卡洛夫" << endl;
			cout << "1进攻/2逃跑" << endl;
			cin >> f;
			if (f == 1)
			{
				fight("卡卡洛夫", 100000, 12000, 2500, 170, 4000);
				if (!dead)
				{
					if (rand() % 3)
					{
						if (rand() % 2)
						{
							cout << "获得技能书恢复如初" << endl;
							bag[12]++;
						}
						else
						{
							cout << "获得技能书阿瓦达索命" << endl;
							bag[18]++;
						}
					}
					if (rand() % 5)
					{
						if (rand() % 5 == 0)
						{
							cout << "获得四瓶经验药水" << endl;
							bag[22] += 4;
						}
						else if (rand() % 5 == 1)
						{
							cout << "获得四瓶攻击药水" << endl;
							bag[21] += 4;
						}
						else if (rand() % 5 == 2)
						{
							cout << "获得四瓶生命药水" << endl;
							bag[19] += 4;
						}
						else if (rand() % 5 == 3)
						{
							cout << "获得三瓶全幅药水" << endl;
							bag[23] += 3;
						}
						else
						{
							cout << "获得四瓶防御药水" << endl;
							bag[20] += 4;
						}
					}
				}
			}
		}
		break;
	case 5:
		if (camp)
		{
			int f;
			cout << "你遇到了邓布利多" << endl;
			cout << "1进攻/2逃跑" << endl;
			cin >> f;
			if (f == 1)
			{
				fight("邓布利多", 300000, 36000, 7500, 20, 5000);
				if (!dead)
				{
					if (rand() % 3)
					{
						if (rand() % 2)
						{
							cout << "获得技能书恢复如初" << endl;
							bag[12]++;
						}
						else
						{
							cout << "获得技能书阿瓦达索命" << endl;
							bag[18]++;
						}
					}
					if (rand() % 5)
					{
						if (rand() % 5 == 0)
						{
							cout << "获得四瓶经验药水" << endl;
							bag[22] += 4;
						}
						else if (rand() % 5 == 1)
						{
							cout << "获得四瓶攻击药水" << endl;
							bag[21] += 4;
						}
						else if (rand() % 5 == 2)
						{
							cout << "获得四瓶生命药水" << endl;
							bag[19] += 4;
						}
						else if (rand() % 5 == 3)
						{
							cout << "获得三瓶全幅药水" << endl;
							bag[23] += 3;
						}
						else
						{
							cout << "获得四瓶防御药水" << endl;
							bag[20] += 4;
						}
					}
				}
			}
		}
		else
		{
			int f;
			cout << "你遇到了纳尼吉" << endl;
			cout << "1进攻/2逃跑" << endl;
			cin >> f;
			if (f == 1)
			{
				fight("纳尼吉", 300000, 36000, 7500, 20, 5000);
				if (!dead)
				{
					if (rand() % 3)
					{
						if (rand() % 2)
						{
							cout << "获得技能书恢复如初" << endl;
							bag[12]++;
						}
						else
						{
							cout << "获得技能书阿瓦达索命" << endl;
							bag[18]++;
						}
					}
					if (rand() % 5)
					{
						if (rand() % 5 == 0)
						{
							cout << "获得四瓶经验药水" << endl;
							bag[22] += 4;
						}
						else if (rand() % 5 == 1)
						{
							cout << "获得四瓶攻击药水" << endl;
							bag[21] += 4;
						}
						else if (rand() % 5 == 2)
						{
							cout << "获得四瓶生命药水" << endl;
							bag[19] += 4;
						}
						else if (rand() % 5 == 3)
						{
							cout << "获得三瓶全幅药水" << endl;
							bag[23] += 3;
						}
						else
						{
							cout << "获得四瓶防御药水" << endl;
							bag[20] += 4;
						}
					}
				}
			}
		}
		if (!dead)
			if (ane1 == 0)
				D_Of_C1++;
		break;
	}
	Sleep(1000);
	return 0;
}
int buy(int p, int m)
{
	if (money < m)
	{
		cout << "没钱，打出去！" << endl;
		if (camp)
		{
			cout << "1抢劫 2逃离" << endl;
			int a;
			cin >> a;
			if (a == 1)
			{
				fight("员工", 1000, 100, 10, 0, 1000);
				if (dead)
					return 0;
				cout << "另外一个员工冲了过来" << endl;
				fight("员工", 1000, 100, 10, 14, 1000);
				if (dead)
					return 0;
				cout << "另外一个员工冲了过来" << endl;
				fight("员工", 1000, 100, 10, 14, 2000);
				if (dead)
					return 0;
				cout << "员工头冲了过来" << endl;
				fight("员工头", 5000, 5000, 10, 14, 2000);
				if (dead)
					return 0;
				cout << "店主冲了过来" << endl;
				fight("店主", 10000, 1000, 100, 15, 4000);
				if (dead)
					return 0;
				cout << "获得100元" << endl;
				money += 100;
				if (rand() % 10 < 3)
				{
					Sleep(3000);
					cout << "你翻了半天，终于找到了你要卖的东西" << endl;
					bag[p]++;
				}
				else
				{
					Sleep(3000);
					cout << "你翻了半天，还是没找到你要卖的东西" << endl;
					cout << "你要不要到大街上消消气（杀人）" << endl;
					cout << "1要！ 2不必了" << endl;
					int q;
					cin >> q;
					if (q == 1)
						street();
				}
			}
		}
	}
	else
	{
		cout << "购买成功" << endl;
		bag[p]++;
		money -= m;
		if (ane == 1)
			D_Of_C++;
		if (ane1 == 1)
			D_Of_C1 += m;
	}
	Sleep(1000);
	return 0;
}
int buywand(int p, int m)
{
	if (money < m)
		cout << "没钱，打出去！" << endl;
	else
	{
		cout << "购买成功" << endl;
		wand[p - 6]++;
		money -= m;
		if (ane == 1)
			D_Of_C++;
		if (ane1 == 1)
			D_Of_C1 += m;
	}
	Sleep(1000);
	return 0;
}
int make(int w1, int w2, int c1, int c2)
{
	if (w1 < 24 || w2 < 33)
	{
		cout << "根本就没有这种材料，你眼瞎啊！" << endl;
		Sleep(1000);
		return 0;
	}
	if (c1 == 0 || c2 == 0)
	{
		cout << "你想拿0个材料来造魔杖！没门!" << endl;
		Sleep(1000);
		return 0;
	}
	if (bag[w1] < c1)
	{
		if (bag[w2] < c2)
			cout << "你木材和杖芯都不够";
		else
			cout << "杖芯不够";
	}
	else if (bag[w2] < c2)
		cout << "木材不够";
	else
	{
		cout << "制作成功" << endl;
		string wn;
		wn = Material1name[w1 - 24] + Material2name[w2 - 33] + "魔杖";
		bag[w1] -= c1;
		bag[w2] -= c2;
		wand[wandi++]++;
		wandpower[wandpoweri++] = c1 * 20 * (w1 - 4) + c1 * 10 * (w2 - 13);
		wandname[wandnamei++] = wn;
	}
	Sleep(1000);
	return 0;
}
int levelup()
{
	if (experience >= level * 100)
	{
		experience -= level * 100;
		level++;
		maxhealth += 100;
		health += 100;
		attack += 10;
		defense += 5;
		speed += 10;
		if (rand() % 2 && level > 4)
			bag[0] += 1;
		cout << "你升了1级" << endl;
		levelup();
		if (ane1 == 4)
			D_Of_C1++;
	}
	return 0;
}
int Hos()
{
	int a;
	if (health < maxhealth)
	{
		cout << "剩余生命：(" << health << "/" << maxhealth << ")" << endl;
		cout << "需要" << ((maxhealth)-health) / 16 << "元 是否恢复. 等级小于等于10免费恢复" << endl;
		cout << "1,是 2,否" << endl;
		cin >> a;
		if (a == 1)
		{
			if (level > 10)
			{
				if (money >= ((maxhealth)-health) / 16)
				{
					money -= ((maxhealth)-health) / 16;
					cout << "恢复成功\n剩余：" << money << "元";
					if (ane == 2)
						D_Of_C++;
					if (ane1 == 1)
						D_Of_C1 += ((maxhealth)-health) / 16;
					health = maxhealth;
				}
				else
					cout << "钱不足" << endl;
			}
			else
			{
				health = maxhealth;
				cout << "恢复成功" << endl;
				if (ane == 2)
					D_Of_C++;
			}
		}
		else if (a == 2)
			return 0;
		else
		{
			cout << "请别乱输";
			Hos();
		}
	}
	else
	{
		cout << "生命已满";
		Sleep(1000);
	}
	return 0;
}
int w()
{
	int aaaa = 1;
	while (aaaa)
	{
		for (int i = 0; i < wandi; i++)
		{
			if (wandname[i] == Nwand)
				cout << "o";
			else
				cout << " ";
			cout << i + 1 << "," << wandname[i] << " " << wand[i] << "个"
				 << "  力量：" << wandpower[i] << endl;
		}
		cout << "1，装备魔杖 2，卸下现有魔杖 0，退出" << endl;
		cin >> aaaa;
		if (aaaa == 1)
		{
			cout << "请输入魔杖编号" << endl;
			int bbbb;
			cin >> bbbb;
			if (wand[bbbb - 1])
			{
				if (Nwand != "空手")
				{
					cout << "已装备魔杖";
					Sleep(1000);
				}
				else
				{
					cout << "装备成功";
					Nwand = wandname[bbbb - 1];
					attack += wandpower[bbbb - 1];
				}
			}
			else
			{
				cout << "您还未拥有此魔杖";
			}
			Sleep(1000);
		}
		else if (aaaa == 2)
		{
			for (int ia = 0; ia < wandi - 1; ia++)
			{
				if (Nwand == wandname[ia])
				{
					cout << "成功卸下";
					attack -= wandpower[ia];
					break;
				}
			}
			Nwand = "空手";
			Sleep(1000);
		}
		else if (aaaa == 0)
			break;
		else
			cout << "请别乱输";
		levelup();
		system("system");
		cout << "魔法人士：" << name << endl;
		cout << "势力：";
		if (camp)
			cout << "伏地魔" << endl;
		else
			cout << "哈利波特" << endl;
		cout << "生命:" << health << "/" << maxhealth << endl;
		cout << "攻击:" << attack << endl;
		cout << "防御:" << defense << endl;
		cout << "速度:" << speed << endl;
		cout << "等级:" << level << endl;
		cout << "经验:" << experience << "/" << level * 100 << endl;
		cout << "金币:" << money << endl;
		cout << "1,魔法部(攻击即可占领) 2,大街(杀人/阻止食死徒) 3,";
		if (camp)
			cout << "霍格沃茨(哈利波特不在) ";
		else
			cout << "伏地魔总部(伏地魔不在) ";
		cout << "4,霍格沃茨(最后战场) 5,奥利凡德魔杖商店 6,抽奖 7,经验石店 8,背包 9,工厂 10,材料店 11,任务 12,终极任务 13,副本 14,保存 ";
		if (camp)
			cout << "15, 医疗兵（伏地魔的）";
		else
			cout << "15, 庞弗雷女士 ";
		cout << "16,改变参数（测试专用 需要密码） 17,设置 18,登出" << endl;
		cout << "8" << endl;
		cout << "1,查看魔杖 2,查看药水 3,查看经验石 4,学习技能" << endl;
		cout << "1" << endl;
	}
	return 0;
}
int e()
{
	int bbbb = 1;
	while (bbbb)
	{
		cout << "1,经验石R " << bag[1] << "个" << endl;
		cout << "2,经验石SR " << bag[2] << "个" << endl;
		cout << "3,经验石SSR " << bag[3] << "个" << endl;
		cout << "4,经验石SSS " << bag[4] << "个" << endl;
		cout << "5,经验石X " << bag[5] << "个" << endl;
		cout << "0,退出 6,一键使用";
		int aaaa;
		cin >> bbbb;
		switch (bbbb)
		{
		case 1:
			cout << "几个？";
			cin >> aaaa;
			if (bag[1] >= aaaa)
			{
				cout << "服用成功";
				experience += aaaa * 100;
				bag[1] -= aaaa;
				Sleep(1000);
				break;
			}
			break;
		case 2:
			cout << "几个？";
			cin >> aaaa;
			if (bag[2] >= aaaa)
			{
				cout << "服用成功";
				experience += aaaa * 250;
				bag[2] -= aaaa;
				Sleep(1000);
				break;
			}
			break;
		case 3:
			cout << "几个？";
			cin >> aaaa;
			if (bag[3] >= aaaa)
			{
				cout << "服用成功";
				experience += aaaa * 500;
				bag[3] -= aaaa;
				Sleep(1000);
				break;
			}
			break;
		case 4:
			cout << "几个？";
			cin >> aaaa;
			if (bag[4] >= aaaa)
			{
				cout << "服用成功";
				experience += aaaa * 1200;
				bag[4] -= aaaa;
				Sleep(1000);
				break;
			}
			break;
		case 5:
			cout << "几个？";
			cin >> aaaa;
			if (bag[5] >= aaaa)
			{
				cout << "服用成功";
				experience += aaaa * 2500;
				bag[5] -= aaaa;
				Sleep(1000);
				break;
			}
			break;
		case 0:
			break;
		case 6:
			cout << "服用成功";
			experience += bag[1] * 100;
			experience += bag[2] * 250;
			experience += bag[3] * 500;
			experience += bag[4] * 1200;
			experience += bag[5] * 2500;
			bag[1] = bag[2] = bag[3] = bag[4] = bag[5] = 0;
			break;
		default:
			cout << "请别乱输";
			Sleep(1000);
			break;
		}
		levelup();
		system("system");
		cout << "魔法人士：" << name << endl;
		cout << "势力：";
		if (camp)
			cout << "伏地魔" << endl;
		else
			cout << "哈利波特" << endl;
		cout << "生命:" << health << "/" << maxhealth << endl;
		cout << "攻击:" << attack << endl;
		cout << "防御:" << defense << endl;
		cout << "速度:" << speed << endl;
		cout << "等级:" << level << endl;
		cout << "经验:" << experience << "/" << level * 100 << endl;
		cout << "金币:" << money << endl;
		cout << "1,魔法部(攻击即可占领) 2,大街(杀人/阻止食死徒) 3,";
		if (camp)
			cout << "霍格沃茨(哈利波特不在) ";
		else
			cout << "伏地魔总部(伏地魔不在) ";
		cout << "4,霍格沃茨(最后战场) 5,奥利凡德魔杖商店 6,抽奖 7,经验石店 8,背包 9,工厂 10,材料店 11,任务 12,终极任务 13,副本 14,保存 ";
		if (camp)
			cout << "15, 医疗兵（伏地魔的）";
		else
			cout << "15, 庞弗雷女士 ";
		cout << "16,改变参数（测试专用 需要密码） 17,设置 18,登出" << endl;
		cout << "8" << endl;
		cout << "1,查看魔杖 2,查看药水 3,查看经验石 4,学习技能" << endl;
		cout << "3" << endl;
	}
	return 0;
}
int p()
{
	int bbbb = 1;
	while (bbbb)
	{
		cout << "1,生命药水 " << bag[19] << "个" << endl;
		cout << "2,防御药水 " << bag[20] << "个" << endl;
		cout << "3,攻击药水 " << bag[21] << "个" << endl;
		cout << "4,经验药水 " << bag[22] << "个" << endl;
		cout << "5,速度药水 " << bag[23] << "个" << endl;
		cout << "6,全幅药水 " << bag[23] << "个" << endl;
		cout << "0,退出 7,一键使用";
		cin >> bbbb;
		int aaaa;
		switch (bbbb)
		{
		case 1:
			cout << "几个？";
			cin >> aaaa;
			if (bag[19] >= aaaa)
			{
				cout << "服用成功";
				health += aaaa * 50;
				maxhealth += aaaa * 50;
				bag[19] -= aaaa;
				Sleep(1000);
				break;
			}
			else
				cout << "物品不足" << endl;
			break;
		case 2:
			cout << "几个？";
			cin >> aaaa;
			if (bag[20] >= aaaa)
			{
				cout << "服用成功";
				defense += aaaa * 10;
				bag[20] -= aaaa;
				Sleep(1000);
				break;
			}
			else
				cout << "物品不足" << endl;
			break;
		case 3:
			cout << "几个？";
			cin >> aaaa;
			if (bag[21] >= aaaa)
			{
				cout << "服用成功";
				attack += aaaa * 25;
				bag[21] -= aaaa;
				Sleep(1000);
				break;
			}
			else
				cout << "物品不足" << endl;
			break;
		case 4:
			cout << "几个？";
			cin >> aaaa;
			if (bag[22] >= aaaa)
			{
				cout << "服用成功";
				experience += aaaa * 200;
				bag[22] -= aaaa;
				Sleep(1000);
				break;
			}
			else
				cout << "物品不足" << endl;
			break;
		case 5:
			cout << "几个？";
			cin >> aaaa;
			if (bag[43] >= aaaa)
			{
				cout << "服用成功";
				speed += aaaa;
				bag[43] -= aaaa;
				Sleep(1000);
				break;
			}
			else
				cout << "物品不足" << endl;
			break;
		case 6:
			cout << "几个？";
			cin >> aaaa;
			if (bag[23] >= aaaa)
			{
				cout << "服用成功";
				health += aaaa * 50;
				maxhealth += aaaa * 50;
				defense += aaaa * 10;
				attack += aaaa * 25;
				experience += aaaa * 200;
				speed += aaaa;
				bag[23] -= aaaa;
				Sleep(1000);
				break;
			}
			else
				cout << "物品不足" << endl;
			break;
		case 7:
			cout << "服用成功";
			health += bag[19] * 50;
			maxhealth += bag[19] * 50;
			defense += bag[20] * 10;
			attack += bag[21] * 25;
			experience += bag[22] * 200;
			speed += bag[43];
			health += bag[23] * 50;
			maxhealth += bag[23] * 50;
			defense += bag[23] * 10;
			attack += bag[23] * 25;
			experience += bag[23] * 200;
			speed += bag[23];
			bag[19] = 0;
			bag[20] = 0;
			bag[21] = 0;
			bag[22] = 0;
			bag[23] = 0;
			bag[43] = 0;
			break;
		case 0:
			break;
		default:
			cout << "请别乱输";
			Sleep(1000);
			break;
		}
		levelup();
		system("system");
		cout << "魔法人士：" << name << endl;
		cout << "势力：";
		if (camp)
			cout << "伏地魔" << endl;
		else
			cout << "哈利波特" << endl;
		cout << "生命:" << health << "/" << maxhealth << endl;
		cout << "攻击:" << attack << endl;
		cout << "防御:" << defense << endl;
		cout << "速度:" << speed << endl;
		cout << "等级:" << level << endl;
		cout << "经验:" << experience << "/" << level * 100 << endl;
		cout << "金币:" << money << endl;
		cout << "1,魔法部(攻击即可占领) 2,大街(杀人/阻止食死徒) 3,";
		if (camp)
			cout << "霍格沃茨(哈利波特不在) ";
		else
			cout << "伏地魔总部(伏地魔不在) ";
		cout << "4,霍格沃茨(最后战场) 5,奥利凡德魔杖商店 6,抽奖 7,经验石店 8,背包 9,工厂 10,材料店 11,任务 12,终极任务 13,副本 14,保存 ";
		if (camp)
			cout << "15, 医疗兵（伏地魔的）";
		else
			cout << "15, 庞弗雷女士 ";
		cout << "16,改变参数（测试专用 需要密码） 17,设置 18,登出" << endl;
		cout << "8" << endl;
		cout << "1,查看魔杖 2,查看药水 3,查看经验石 4,学习技能" << endl;
		cout << "2" << endl;
	}
	return 0;
}
int s()
{
	int bbbb = 1;
	while (bbbb)
	{
		cout << "1,快快复苏 " << bag[6] << "个" << endl;
		cout << "2,盔甲护身 " << bag[7] << "个" << endl;
		cout << "3,昏昏倒地 " << bag[8] << "个" << endl;
		cout << "4,神锋无影 " << bag[9] << "个" << endl;
		cout << "5,咒立停 " << bag[10] << "个" << endl;
		cout << "6,统统石化 " << bag[11] << "个" << endl;
		cout << "7,恢复如初 " << bag[12] << "个" << endl;
		cout << "8,召唤咒 " << bag[13] << "个" << endl;
		cout << "9,一忘皆空 " << bag[14] << "个" << endl;
		cout << "10,万箭齐发 " << bag[15] << "个" << endl;
		cout << "11,钻心剜骨 " << bag[16] << "个" << endl;
		cout << "12,魂魄出窍 " << bag[17] << "个" << endl;
		cout << "13,阿瓦达索命 " << bag[18] << "个" << endl;
		cout << "0，退出";
		cin >> bbbb;
		switch (bbbb)
		{
		case 1:
			if (bag[6] >= 1)
			{
				cout << "学习成功" << endl;
				cout << "能够恢复200滴血" << endl;
				bag[6] -= 1;
				Sl[0] = 1;
				Sleep(1000);
				break;
			}
			else
				cout << "物品不足" << endl;
			break;
		case 2:
			if (bag[7] >= 1)
			{
				cout << "学习成功" << endl;
				cout << "能恢复100滴血并加50防御" << endl;
				bag[7] -= 1;
				Sl[1] = 1;
				Sleep(1000);
				break;
			}
			else
				cout << "物品不足" << endl;
			break;
		case 3:
			if (bag[8] >= 1)
			{
				cout << "学习成功" << endl;
				cout << "能使对方暂停一回合" << endl;
				bag[8] -= 1;
				Sl[2] = 1;
				Sleep(1000);
				break;
			}
			else
				cout << "物品不足" << endl;
			break;
		case 4:
			if (bag[9] >= 1)
			{
				cout << "学习成功" << endl;
				cout << "攻击加250并扣对方500滴血" << endl;
				bag[9] -= 1;
				Sl[3] = 1;
				Sleep(1000);
				break;
			}
			else
				cout << "物品不足" << endl;
			break;
		case 5:
			if (bag[10] >= 1)
			{
				cout << "学习成功" << endl;
				cout << "能使对方对你施加的状态没用" << endl;
				bag[10] -= 1;
				Sl[4] = 1;
				Sleep(1000);
				break;
			}
			else
				cout << "物品不足" << endl;
			break;
		case 6:
			if (bag[11] >= 1)
			{
				cout << "学习成功" << endl;
				cout << "%10概率能事对方冻结10回合" << endl;
				cout << "%90概率能事对方冻结2回合" << endl;
				bag[11] -= 1;
				Sl[5] = 1;
				Sleep(1000);
				break;
			}
			else
				cout << "物品不足" << endl;
			break;
		case 7:
			if (bag[12] >= 1)
			{
				cout << "学习成功" << endl;
				cout << "%50概率能起死回生" << endl;
				bag[12] -= 1;
				Sl[6] = 1;
				Sleep(1000);
				break;
			}
			else
				cout << "物品不足" << endl;
			break;
		case 8:
			if (bag[13] >= 1)
			{
				cout << "学习成功" << endl;
				cout << "能召唤生物进攻" << endl;
				bag[13] -= 1;
				Sl[7] = 1;
				Sleep(1000);
				break;
			}
			else
				cout << "物品不足" << endl;
			break;
		case 9:
			if (bag[14] >= 1)
			{
				cout << "学习成功" << endl;
				cout << "%90能使对方无技能" << endl;
				cout << "%10能使对方防御变为0" << endl;
				bag[14] -= 1;
				Sl[8] = 1;
				Sleep(1000);
				break;
			}
			else
				cout << "物品不足" << endl;
			break;
		case 10:
			if (bag[15] >= 1)
			{
				cout << "学习成功" << endl;
				cout << "对方一直减10滴血直到对方躲过（%10躲过）" << endl;
				bag[15] -= 1;
				Sl[9] = 1;
				Sleep(1000);
				break;
			}
			else
				cout << "物品不足" << endl;
			break;
		case 11:
			if (bag[16] >= 1)
			{
				cout << "学习成功" << endl;
				cout << "对方扣血5回合，每回合扣200滴" << endl;
				bag[16] -= 1;
				Sl[10] = 1;
				Sleep(1000);
				break;
			}
			else
				cout << "物品不足" << endl;
			break;
		case 12:
			if (bag[17] >= 1)
			{
				cout << "学习成功" << endl;
				cout << "让对方自己攻击自己（当然不攻击你）" << endl;
				bag[17] -= 1;
				Sl[11] = 1;
				Sleep(1000);
				break;
			}
			else
				cout << "物品不足" << endl;
			break;
		case 13:
			if (bag[18] >= 1)
			{
				cout << "学习成功" << endl;
				cout << "让对方直接扣3/4的血" << endl;
				bag[18] -= 1;
				Sl[12] = 1;
				Sleep(1000);
				break;
			}
			else
				cout << "物品不足" << endl;
			break;
		case 0:
			break;
		default:
			cout << "请别乱输";
			Sleep(1000);
			break;
		}
		system("system");
		cout << "魔法人士：" << name << endl;
		cout << "势力：";
		if (camp)
			cout << "伏地魔" << endl;
		else
			cout << "哈利波特" << endl;
		cout << "生命:" << health << "/" << maxhealth << endl;
		cout << "攻击:" << attack << endl;
		cout << "防御:" << defense << endl;
		cout << "速度:" << speed << endl;
		cout << "等级:" << level << endl;
		cout << "经验:" << experience << "/" << level * 100 << endl;
		cout << "金币:" << money << endl;
		cout << "1,魔法部(攻击即可占领) 2,大街(杀人/阻止食死徒) 3,";
		if (camp)
			cout << "霍格沃茨(哈利波特不在) ";
		else
			cout << "伏地魔总部(伏地魔不在) ";
		cout << "4,霍格沃茨(最后战场) 5,奥利凡德魔杖商店 6,抽奖 7,经验石店 8,背包 9,工厂 10,材料店 11,任务 12,终极任务 13,副本 14,保存 ";
		if (camp)
			cout << "15, 医疗兵（伏地魔的）";
		else
			cout << "15, 庞弗雷女士 ";
		cout << "16,改变参数（测试专用 需要密码） 17,设置 18,登出" << endl;
		cout << "8" << endl;
		cout << "1,查看魔杖 2,查看药水 3,查看经验石 4,学习技能" << endl;
		cout << "4" << endl;
	}
	return 0;
}
int LD()
{
	cout << "剩余抽奖券:" << bag[0] << "张" << endl;
	cout << "1,抽奖 2,退出" << endl;
	int a;
	cin >> a;
	if (a == 1)
	{
		cout << "抽几次？";
		int num;
		cin >> num;
		if (bag[0] >= num)
		{
			bag[0] -= num;
			int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0;
			int num6 = 0, num7 = 0, num8 = 0, num9 = 0, num10 = 0;
			int num11 = 0;
			for (int i = 0; i < num; i++)
			{
				switch (rand() % 20)
				{
				case 0:
				case 1:
					num1++;
					bag[1]++;
					break;
				case 2:
				case 3:
					num2++;
					bag[2]++;
					break;
				case 4:
				case 5:
					num3++;
					bag[3]++;
					break;
				case 6:
				case 7:
					num4++;
					bag[4]++;
					break;
				case 8:
					num5++;
					bag[5]++;
					break;
				case 9:
				case 10:
					num6++;
					bag[19]++;
					break;
				case 11:
				case 12:
					num7++;
					bag[20]++;
					break;
				case 13:
				case 14:
					num8++;
					bag[21]++;
					break;
				case 15:
				case 16:
					num9++;
					bag[22]++;
					break;
				case 17:
					num10++;
					bag[23]++;
					break;
				case 18:
					num11 += 50;
					money += 50;
					break;
				case 19:
					num11 += 100;
					money += 100;
					break;
				}
			}
			cout << "你获得了经验石R   " << num1 << "个" << endl;
			cout << "经验石SR         " << num2 << "个" << endl;
			cout << "经验石SSR        " << num3 << "个" << endl;
			cout << "经验石SSS        " << num4 << "个" << endl;
			cout << "经验石X          " << num5 << "个" << endl;
			cout << "生命药水         " << num6 << "个" << endl;
			cout << "防御药水         " << num7 << "个" << endl;
			cout << "攻击药水         " << num8 << "个" << endl;
			cout << "经验药水         " << num9 << "个" << endl;
			cout << "全幅药水         " << num10 << "个" << endl;
			cout << "金币             " << num11 << "个" << endl;
		}
		else
			cout << "您的抽奖券不足" << endl;
	}
	else if (a == 2)
		return 0;
	else
	{
		cout << "请别乱输。";
		system("system");
		LD();
	}
	_getch();
	return 0;
}
int dig()
{
	cout << "进入挖矿状态";
	Sleep(1000);
	system("system");
	int x = 0;
	while (1)
	{
		system("system");
		cout << "挖";
		Sleep(200);
		cout << "矿";
		Sleep(200);
		cout << "中";
		Sleep(200);
		cout << ".";
		Sleep(100);
		cout << ".";
		Sleep(100);
		cout << "." << endl;
		x++;
		Sleep(500);
		int ad = rand() % 3;
		if (ad == 2)
		{
			ad = rand() % 100;
			if (ad < 6)
			{
				switch (rand() % 3)
				{
				case 0:
					cout << "你挖到了技能书铁甲咒！！！" << endl;
					bag[7]++;
					break;
				case 1:
					cout << "你挖到了技能书咒立停！！！" << endl;
					bag[10]++;
					break;
				case 2:
					cout << "你挖到了技能书石化咒！！！" << endl;
					bag[11]++;
					break;
				}
				Sleep(500);
			}
			else if (ad >= 6 && ad < 20)
			{
				switch (rand() % 20)
				{
				case 0:
					cout << "你挖到了夜琪的尾羽！！！" << endl;
					bag[32]++;
					break;
				case 1:
				case 2:
					cout << "你挖到了独角兽尾毛！" << endl;
					bag[30]++;
					break;
				case 3:
				case 4:
					cout << "你挖到了龙神经！" << endl;
					bag[31]++;
					break;
				case 5:
				case 6:
					cout << "你挖到了凤凰羽毛！" << endl;
					bag[29]++;
					break;
				case 7:
				case 8:
					cout << "你挖到了龙心腱" << endl;
					bag[27]++;
					break;
				case 9:
				case 10:
					cout << "你挖到了雷鸟尾羽" << endl;
					bag[28]++;
					break;
				case 11:
				case 12:
				case 13:
					cout << "你挖到了马形水怪的鬃毛" << endl;
					bag[26]++;
					break;
				case 14:
				case 15:
				case 16:
					cout << "你挖到了猫狸子胡须" << endl;
					bag[24]++;
					break;
				case 17:
				case 18:
				case 19:
					cout << "你挖到了媚娃头发" << endl;
					bag[25]++;
					break;
				}
				Sleep(500);
			}
			else if (ad >= 20 && ad < 50)
			{
				switch (rand() % 10)
				{
				case 0:
					cout << "你挖到了桦木" << endl;
					bag[33]++;
					break;
				case 1:
					cout << "你挖到了紫衫木" << endl;
					bag[34]++;
					break;
				case 2:
					cout << "你挖到了冬青木" << endl;
					bag[35]++;
					break;
				case 3:
					cout << "你挖到了山楂木柳条" << endl;
					bag[36]++;
					break;
				case 4:
					cout << "你挖到了橡木" << endl;
					bag[37]++;
					break;
				case 5:
					cout << "你挖到了械木" << endl;
					bag[38]++;
					break;
				case 6:
					cout << "你挖到了山毛榉木" << endl;
					bag[39]++;
					break;
				case 7:
					cout << "你挖到了栗木" << endl;
					bag[40]++;
					break;
				case 8:
					cout << "你挖到了樱桃木" << endl;
					bag[41]++;
					break;
				case 9:
					cout << "你挖到了桃花心木" << endl;
					bag[42]++;
					break;
				}
				Sleep(500);
			}
			else if (ad >= 50 && ad <= 100)
			{
				int as = rand() % 20 + 30;
				cout << "你挖到了" << as << "金币" << endl;
				money += as;
				Sleep(500);
			}
		}
		else if (ad == 1)
		{
			ad = rand() % 3;
			if (ad == 0)
			{
				cout << "你遇到了大老鼠" << endl;
				fight("大老鼠", 5000, 500, 50, 20, 1000);
				if (dead)
				{
					cout << "你死了" << endl;
					return 0;
				}
			}
			if (ad == 1)
			{
				cout << "你遇到了食死徒" << endl;
				fight("食死徒", 10000, 1000, 100, 17, 1000);
				if (dead)
				{
					cout << "你死了" << endl;
					return 0;
				}
			}
			if (ad == 2)
			{
				cout << "你遇到了坏矿工" << endl;
				fight("矿工", 5000, 2000, 200, 17, 1000);
				if (dead)
				{
					cout << "你死了" << endl;
					return 0;
				}
			}
			cout << "是否继续挖矿？" << endl;
			cout << "1,是 2,否" << endl;
			int ans;
			cin >> ans;
			if (ans == 2)
				return 0;
		}
	}
	return 0;
}
int clearance()
{
	system("system");
	cout << "你在出口处发现了一张纸条，上面写着：";
	if (camp)
	{
		cout << "伏地魔，我知道你在找我...我就告诉你吧，我在霍格沃茨等你！" << endl;
		cout << "                                           ————哈利·波特" << endl;
	}
	else
	{
		cout << "哈利·波特, 你看到这张纸条的时候, 你们的校已经掌握在我手中, 要么你前来送死，要么我就会把你的同们统统杀死！！！" << endl;
		cout << "                                                                                               ——伏地魔" << endl;
	}
	_getch();
	f = 1;
	return 0;
}
int maze()
{
	bool is[101][101];
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			is[i][j] = false;
	int x = 8, y = 1;
	string a[100] = {
		"##################################################",
		"# 1   #   2  2 3#  #  1 #89#1#1# 1 1  #12  #3  #1#",
		"#2#1#5  # #1# #   ## # ##91  6   #9#7#11## # # 11#",
		"#   ## ## # # # #### # #####  # ####5##  # # #####",
		"#2########### # 4 #      ##  #####4    5##1# #189o",
		"# 1  1#     #2# ##  # ##   5#    ######### # #7#8#",
		"#1# #1 2# #     #  #9 # ### # ##2## #   ##  5#167#",
		"#  1## ## # # ### #4##  ##  6 #  3  ###   #####5##",
		"I 2 #### #### #  1 6   #1# ##  5###6##  # #11134##",
		"I  1  #      7 # # # #   227# #  #   # #2 #2#21#5#",
		"##1 #1  #1# ## 5 #   # #3####  #  1#5# # 1 111#6 #",
		"#  2##3##1# ### ## ### #    ## ####  # #1####### #",
		"# ##3  ##1###7#    ##### ##  #   ###3  4## 9   # #",
		"#23   #    3   # ##9 ##6 6##   ### 9## ##1 # #3  #",
		"# # #   # # ## # ##    ##7 ## # 9  ###9#11##2## ##",
		"### # #######  # 2 # #3 # # #  1## 1 1## ##1 #3  #",
		"#5  #2   ## # #### # #5#  # ### #8###1   #1# #1# #",
		"# # # #   # # 4 5  # #  # 7   # # #   ####  8  #9#",
		"#   2 # #42   # ##    # 11#2#3   9  # ##9  # #999#",
		"##################################################",
	};
	while (1)
	{
		is[x - 1][y - 1] = true;
		is[x - 1][y] = true;
		is[x - 1][y + 1] = true;
		is[x][y - 1] = true;
		is[x][y] = true;
		is[x][y + 1] = true;
		is[x + 1][y - 1] = true;
		is[x + 1][y] = true;
		is[x + 1][y + 1] = true;
		system("system");
		cout << "生命:" << health << "/" << maxhealth << endl;
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 50; j++)
			{
				if (is[i][j])
					cout << a[i][j];
				else
					cout << "0";
			}
			cout << endl;
		}
		int ch;
		ch = _getch();
		if (ch == 'a')
		{
			if (a[x][y - 1] == ' ')
			{
				a[x][y - 1] = '@';
				a[x][y] = ' ';
				y -= 1;
			}
			else if ('0' <= a[x][y - 1] && a[x][y - 1] <= '9')
			{
				cout << "你遇到了" << (int)(a[x][y - 1] - '0') << "级怪物，迎战吧！";
				fight("怪物", 10000 * (a[x][y - 1] - '0'), 2500 * (a[x][y - 1] - '0'), 100 * (a[x][y - 1] - '0'), 20, 500 * (a[x][y - 1] - '0'));
				if (dead)
				{
					Sleep(1000);
					return 0;
				}
				a[x][y - 1] = '@';
				a[x][y] = ' ';
				y -= 1;
				a[x][y] = ' ';
			}
			else if (a[x][y - 1] == 'I')
			{
				cout << "你是否要退出这个奇怪的世界，如果退出，你现在闯下的江湖都会重置" << endl;
				cout << "1确定 2取消" << endl;
				int num;
				cin >> num;
				if (num == 1)
				{
					break;
				}
			}
			else if (a[x][y - 1] == 'o')
			{
				cout << "你通关了" << endl;
				_getch();
				clearance();
			}
		}
		if (ch == 'd')
		{
			if (a[x][y + 1] == ' ')
			{
				a[x][y + 1] = '@';
				a[x][y] = ' ';
				y += 1;
			}
			else if ('0' <= a[x][y + 1] && a[x][y + 1] <= '9')
			{
				cout << "你遇到了" << (int)(a[x][y + 1] - '0') << "级怪物，迎战吧！";
				fight("怪物", 10000 * (a[x][y + 1] - '0'), 2500 * (a[x][y + 1] - '0'), 100 * (a[x][y + 1] - '0'), 20, 500 * (a[x][y + 1] - '0'));
				if (dead)
				{
					Sleep(1000);
					return 0;
				}
				a[x][y + 1] = '@';
				a[x][y] = ' ';
				y += 1;
				a[x][y] = ' ';
			}
			else if (a[x][y + 1] == 'I')
			{
				cout << "你是否要退出这个奇怪的世界，如果退出，你现在闯下的江湖都会重置" << endl;
				cout << "1确定 2取消" << endl;
				int num;
				cin >> num;
				if (num == 1)
				{
					break;
				}
			}
			else if (a[x][y + 1] == 'o')
			{
				cout << "你通关了" << endl;
				_getch();
				clearance();
			}
		}
		if (ch == 'w')
		{
			if (a[x - 1][y] == ' ')
			{
				a[x - 1][y] = '@';
				a[x][y] = ' ';
				x -= 1;
			}
			else if ('0' <= a[x - 1][y] && a[x - 1][y] <= '9')
			{
				cout << "你遇到了" << (int)(a[x - 1][y] - '0') << "级怪物，迎战吧！";
				fight("怪物", 10000 * (a[x - 1][y] - '0'), 2500 * (a[x - 1][y] - '0'), 100 * (a[x - 1][y] - '0'), 20, 500 * (a[x - 1][y] - '0'));
				if (dead)
				{
					Sleep(1000);
					return 0;
				}
				a[x - 1][y] = '@';
				a[x][y] = ' ';
				x -= 1;
				a[x][y] = ' ';
			}
			else if (a[x - 1][y] == 'I')
			{
				cout << "你是否要退出这个奇怪的世界，如果退出，你现在闯下的江湖都会重置" << endl;
				cout << "1确定 2取消" << endl;
				int num;
				cin >> num;
				if (num == 1)
				{
					break;
				}
			}
			else if (a[x - 1][y] == 'o')
			{
				cout << "你通关了" << endl;
				_getch();
				clearance();
			}
		}
		if (ch == 's')
		{
			if (a[x + 1][y] == ' ')
			{
				a[x + 1][y] = '@';
				a[x][y] = ' ';
				x += 1;
			}
			else if ('0' <= a[x + 1][y] && a[x + 1][y] <= '9')
			{
				cout << "你遇到了" << (int)(a[x + 1][y] - '0') << "级怪物，迎战吧！";
				fight("怪物", 10000 * (a[x + 1][y] - '0'), 2500 * (a[x + 1][y] - '0'), 100 * (a[x + 1][y] - '0'), 20, 500 * (a[x + 1][y] - '0'));
				if (dead)
				{
					Sleep(1000);
					return 0;
				}
				a[x + 1][y] = '@';
				a[x][y] = ' ';
				x += 1;
				a[x][y] = ' ';
			}
			else if (a[x + 1][y] == 'I')
			{
				cout << "你是否要退出这个奇怪的世界，如果退出，你现在闯下的江湖都会重置" << endl;
				cout << "1确定 2取消" << endl;
				int num;
				cin >> num;
				if (num == 1)
				{
					break;
				}
			}
			else if (a[x + 1][y] == 'o')
			{
				cout << "你通关了" << endl;
				_getch();
				clearance();
			}
		}
	}
	return 0;
}
int DriveOut()
{
	switch (rand() % 3)
	{
	case 1:
		cout << "店主：没钱还敢卖！！！打出去！！！" << endl;
		break;
	case 2:
		cout << "店主：什么！没钱！！！" << endl;
		break;
	case 3:
		cout << "你：可不可以降一降价？" << endl;
		cout << "店主：不行！哪有那么简单！" << endl;
		break;
	}
	Sleep(1000);
	return 0;
}
int poisonshop()
{
	system("system");
	cout << "店主：这位客人，您要卖什么？" << endl;
	cout << "1,购买      |小生命药水+200|     100元" << endl;
	cout << "2,购买     ||大生命药水+500||    200元" << endl;
	cout << "3,购买      |小防御药水 +20|     100元" << endl;
	cout << "4,购买     ||大防御药水 +50||    200元" << endl;
	cout << "5,购买      |小攻击药水+100|     100元" << endl;
	cout << "6,购买     ||大攻击药水+250||    200元" << endl;
	cout << "7,购买        |小全幅药水|       500元" << endl;
	cout << "8,购买       ||中全幅药水||      1000元" << endl;
	cout << "9,购买      |||大全幅药水|||     2000元" << endl;
	cout << "10,购买 *|||||极·全幅药水|||||*  10000元" << endl;
	cout << "你掏了掏自己的钱包，发现有" << money << "元" << endl;
	int which;
	cin >> which;
	switch (which)
	{
	case 1:
		if (money < 100)
			DriveOut();
		else
		{
			money -= 100;
			cout << "店主：一路走好！" << endl;
			cout << "你拿起药水就喝了下去。" << endl;
			health += 200;
			maxhealth += 200;
		}
		break;
	case 2:
		if (money < 200)
			DriveOut();
		else
		{
			money -= 200;
			cout << "店主：一路走好！" << endl;
			cout << "你拿起药水就喝了下去。" << endl;
			health += 500;
			maxhealth += 500;
		}
		break;
	case 3:
		if (money < 100)
			DriveOut();
		else
		{
			money -= 100;
			cout << "店主：一路走好！" << endl;
			cout << "你拿起药水就喝了下去。" << endl;
			defense += 20;
		}
		break;
	case 4:
		if (money < 200)
			DriveOut();
		else
		{
			money -= 200;
			cout << "店主：一路走好！" << endl;
			cout << "你拿起药水就喝了下去。" << endl;
			defense += 50;
		}
		break;
	case 5:
		if (money < 100)
			DriveOut();
		else
		{
			money -= 100;
			cout << "店主：一路走好！" << endl;
			cout << "你拿起药水就喝了下去。" << endl;
			attack += 100;
		}
		break;
	case 6:
		if (money < 200)
			DriveOut();
		else
		{
			money -= 200;
			cout << "店主：一路走好！" << endl;
			cout << "你拿起药水就喝了下去。" << endl;
			attack += 250;
		}
		break;
	case 7:
		if (money < 500)
			DriveOut();
		else
		{
			money -= 500;
			cout << "店主：一路走好！" << endl;
			cout << "你拿起药水就喝了下去。" << endl;
			health += 50;
			defense += 5;
			attack += 25;
			experience += 1000;
		}
		break;
	case 8:
		if (money < 1000)
			DriveOut();
		else
		{
			money -= 1000;
			cout << "店主：一路走好！" << endl;
			cout << "你拿起药水就喝了下去。" << endl;
			health += 150;
			defense += 15;
			attack += 75;
			experience += 3000;
		}
		break;
	case 9:
		if (money < 2000)
			DriveOut();
		else
		{
			money -= 2000;
			cout << "店主：一路走好！" << endl;
			cout << "你拿起药水就喝了下去。" << endl;
			health += 450;
			defense += 45;
			attack += 225;
			experience += 9000;
		}
		break;
	case 10:
		if (money < 10000)
			DriveOut();
		else
		{
			money -= 10000;
			cout << "店主：一路走好！" << endl;
			cout << "你拿起药水就喝了下去。" << endl;
			health += 2500;
			defense += 250;
			attack += 1250;
			experience += 50000;
		}
		break;
	default:
		break;
	}
	Sleep(1000);
	return 0;
}
int bookshop()
{
	system("system");
	cout << "店主：这里是巫师们卖书的地方，您要卖什么？" << endl;
	cout << "1,购买  ||||恢复如初技能书||||   40000元  现货大量供应" << endl;
	cout << "2,购买     ||遗忘咒技能书||      10000元  已经售完" << endl;
	cout << "3,购买    |||钻心咒技能书|||     15000元  现货大量供应" << endl;
	cout << "4,购买    |||召唤咒技能书|||     20000元  现货大量供应" << endl;
	cout << "5,购买 *|||||咒立停技能书|||||*  25000元  现货大量供应" << endl;
	cout << "6,购买   ||||夺魂咒技能书||||    20000元  现货大量供应" << endl;
	cout << "7,购买    ||万弹齐发技能书||     15000元  现货大量供应" << endl;
	cout << "你掏了掏自己的钱包，发现有" << money << "元" << endl;
	int which;
	cin >> which;
	switch (which)
	{
	case 1:
		if (money < 40000)
			DriveOut();
		else
		{
			money -= 40000;
			cout << "店主：一路走好！" << endl;
			bag[12]++;
		}
		break;
	case 2:
		cout << "店主：对不起，本书已经售完" << endl;
		break;
	case 3:
		if (money < 20000)
			DriveOut();
		else
		{
			money -= 20000;
			cout << "店主：一路走好！" << endl;
			bag[16]++;
		}
		break;
	case 4:
		if (money < 20000)
			DriveOut();
		else
		{
			money -= 20000;
			cout << "店主：一路走好！" << endl;
			bag[13]++;
		}
		break;
	case 5:
		if (money < 25000)
			DriveOut();
		else
		{
			money -= 25000;
			cout << "店主：一路走好！" << endl;
			bag[10]++;
		}
		break;
	case 6:
		if (money < 20000)
			DriveOut();
		else
		{
			money -= 20000;
			cout << "店主：一路走好！" << endl;
			bag[17]++;
		}
		break;
	case 7:
		if (money < 15000)
			DriveOut();
		else
		{
			money -= 15000;
			cout << "店主：一路走好！" << endl;
			bag[15]++;
		}
		break;
	default:
		break;
	}
	return 0;
}
int NoticeBoard(int l, int x, int y)
{
	if (l == 10 && x == 6 && y == 1)
	{
		system("system");
		cout << "跟着'*'走" << endl;
		cout << "     ——作者" << endl;
		_getch();
	}
	if (l == 10 && x == 8 && y == 12)
	{
		system("system");
		cout << "走吧，谁叫你不听命令呢..." << endl;
		cout << "                  ——作者" << endl;
		_getch();
	}
	if (l == 12 && x == 3 && y == 1)
	{
		system("system");
		cout << "杀出重围！" << endl;
		cout << "      ——作者" << endl;
		_getch();
	}
	if (l == 12 && x < 4 && y == 20)
	{
		system("system");
		cout << "恭喜通过一半！往下走继续..." << endl;
		cout << "       ——作者" << endl;
		_getch();
	}
	if (l == 12 && x > 4 && y == 20)
	{
		system("system");
		cout << "恭喜通过一半！往上走继续..." << endl;
		cout << "       ——作者" << endl;
		_getch();
	}
	if (l == 12 && x == 10)
	{
		system("system");
		cout << "拿走全部奖励吧！" << endl;
		cout << "       ——作者" << endl;
		_getch();
	}
	else
	{
		system("system");
		cout << "回去吧，你来错地方了..." << endl;
		_getch();
	}
	return 0;
}
int checkpoint(int l)
{
	bool is[101][101];
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			is[i][j] = false;
	int x = 1, y = 1;
	string a[100];
	if (l == 1)
	{
		a[0] = "######";
		a[1] = "I    o";
		a[2] = "######";
	}
	else if (l == 2)
	{
		a[0] = "#######";
		a[1] = "I    1#";
		a[2] = "#### ##";
		a[3] = "##1  ##";
		a[4] = "#### ##";
		a[5] = "#P    o";
		a[6] = "#######";
	}
	else if (l == 3)
	{
		a[0] = "#########";
		a[1] = "I #  1#S#";
		a[2] = "# ## ##1#";
		a[3] = "# 2     #";
		a[4] = "#### ## #";
		a[5] = "#P1  #o #";
		a[6] = "#########";
	}
	else if (l == 4)
	{
		a[0] = "#######o#######";
		a[1] = "I       #P3   #";
		a[2] = "#       ##### #";
		a[3] = "#         1P  #";
		a[4] = "#       ##### #";
		a[5] = "#S      #    2#";
		a[6] = "######### #####";
		a[7] = "#P121 2 1  11P#";
		a[8] = "###############";
	}
	else if (l == 5)
	{
		a[0] = "###############";
		a[1] = "I 3     #P3   #";
		a[2] = "# 3 #   ##### #";
		a[3] = "# 2 #     1   #";
		a[4] = "# 2 # # ##### #";
		a[5] = "# 1 # #P#    2#";
		a[6] = "#####2S## ###o#";
		a[7] = "#P1 1 # 1   1P#";
		a[8] = "###############";
	}
	else if (l == 6)
	{
		a[0] = "###############";
		a[1] = "#   11  2  6PP#";
		a[2] = "#2# #P#########";
		a[3] = "#2##### #S#   o";
		a[4] = "I       #2# ###";
		a[5] = "# #####  11 ###";
		a[6] = "# #P##### #####";
		a[7] = "#1112       4P#";
		a[8] = "###############";
		x = 4;
	}
	else if (l == 7)
	{
		a[0] = "###############";
		a[1] = "#3 4#  P#  # B#";
		a[2] = "#1# #9## 1#  3#";
		a[3] = "#1#6# 9#  # ###";
		a[4] = "I #7   94 # # o";
		a[5] = "# #1 3 ##  P# #";
		a[6] = "# ########### #";
		a[7] = "#       1  P  #";
		a[8] = "###############";
		x = 4;
	}
	else if (l == 8)
	{
		a[0] = "#################";
		a[1] = "#PPPPPPPPPPPPPPP#";
		a[2] = "#P#############P#";
		a[3] = "#PPPP 9999999 PP#";
		if (rand() % 100 < 7)
			a[4] = "#################";
		else
			a[4] = "######### #######";
		a[5] = "#2 2#2 2#9##2  P#";
		a[6] = "# # # # # #22#  #";
		a[7] = "# # # # # # #22##";
		a[8] = "I # # # # # # # o";
		a[9] = "##22# # # # # # #";
		a[10] = "#  #22# #3# # # #";
		a[11] = "#P  2##2 5 2#2 2#";
		a[12] = "#################";
		x = 8;
	}
	else if (l == 9)
	{
		a[0] = "#################";
		a[1] = "I     9###9     I";
		a[2] = "#      # #      #";
		a[3] = "#    ##P9P##    #";
		a[4] = "#   9# 9o9 #9   #";
		a[5] = "#    ##P9P##    #";
		a[6] = "#      # #      #";
		a[7] = "I     9###9     I";
		a[8] = "#################";
		if (rand() % 2)
			x = 7;
		if (rand() % 2)
			y = 15;
	}
	else if (l == 10)
	{
		a[0] = "#############################";
		a[1] = "#00*****009***P0000000000000#";
		a[2] = "#0*9000*00*000*0**P000000000#";
		a[3] = "#0*000**00*0#0*0900*****00**o";
		a[4] = "#0*00**00*90#0******000****0#";
		a[5] = "#0*00*00**00#0000000***00000#";
		a[6] = "#T*00*90*00##################";
		a[7] = "I**000***00#================I";
		a[8] = "############T################";
		x = 7;
		y = 1;
	}
	else if (l == 11)
	{
		a[0] = "#############################";
		a[1] = "#        33344555#P         #";
		a[2] = "#22222P  33344566#P         ##";
		a[3] = "#11   2  33344567#7 8 8 8 8 9######################";
		a[4] = "I 1   2  33344567           999999999999999  PPPPo#";
		a[5] = "#11   2  33344567#7 8 8 8 8 9######################";
		a[6] = "#22222P  33344566#P         ##";
		a[7] = "#        33344555#P         #";
		a[8] = "#############################";
		x = 4;
		y = 1;
	}
	else if (l == 12)
	{
		a[0] = "###################################################";
		a[1] = "#999999999999999999.T.999999999P999999999999999999#";
		a[2] = "#9999999999.99.99.99T.999999999P999999999999999999#";
		a[3] = "#T9...99.99999999999T.999999999P9999999999999999..#";
		a[4] = "I...9.9.9999.999.99...999999999P9999999999999999.X#";
		a[5] = "#T9...99999999.99999T.999999999P9999999999999999..#";
		a[6] = "#9999999.99.999.99.9T.999999999P999999999999999999#";
		a[7] = "#99999.9999999999999T.999999999P999999999999999999#";
		a[8] = "###################################################";
		a[9] = "#oPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP #";
		a[10] = "#################################################T#";
		x = 4;
		y = 1;
	}
	else
	{
		a[0] = "#############################";
		a[1] = "#T                         T#";
		a[2] = "#                           #";
		a[3] = "#                           #";
		a[4] = "#                           #";
		a[5] = "#                           #";
		a[6] = "#                           #";
		a[7] = "I                          T#";
		a[8] = "#############################";
		x = 7;
		y = 1;
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				is[i][j] = true;
	}
	a[x][y] = '@';
	while (1)
	{
		is[x - 1][y - 1] = true;
		is[x - 1][y] = true;
		is[x - 1][y + 1] = true;
		is[x][y - 1] = true;
		is[x][y] = true;
		is[x][y + 1] = true;
		is[x + 1][y - 1] = true;
		is[x + 1][y] = true;
		is[x + 1][y + 1] = true;
		system("system");
		cout << "生命:" << health << "/" << maxhealth << endl;
		cout << "攻击:" << attack << endl;
		cout << "防御:" << defense << endl;
		for (int i = 0; i < 25; i++)
		{
			for (int j = 0; j < 50; j++)
			{
				if (is[i][j])
					cout << a[i][j];
				else
					cout << "0";
			}
			cout << endl;
		}
		int ch;
		ch = _getch();
		if (ch == 'a')
		{
			if ('0' < a[x][y - 1] && a[x][y - 1] <= '9')
			{
				cout << "你遇到了" << (int)(a[x][y - 1] - '0') << "级怪物，迎战吧！";
				fight("怪物", 1000 * (a[x][y - 1] - '0'), 250 * (a[x][y - 1] - '0'), 10 * (a[x][y - 1] - '0'), 12, 50 * (a[x][y - 1] - '0'));
				if (dead)
				{
					Sleep(1000);
					return 0;
				}
				a[x][y - 1] = '@';
				a[x][y] = ' ';
				y--;
				a[x][y] = ' ';
			}
			else if (a[x][y - 1] == 'I')
			{
				cout << "你是否要退出？" << endl;
				cout << "1确定 2取消" << endl;
				int num;
				cin >> num;
				if (num == 1)
				{
					break;
				}
			}
			else if (a[x][y - 1] == 'o')
			{
				cout << "你通关了" << endl;
				if (nowlevel + 1 == l)
				{
					nowlevel++;
				}
				_getch();
				return 0;
			}
			else if (a[x][y - 1] == 'P')
			{
				int m1 = rand() % 50;
				int m2 = rand() % 2;
				int m3 = rand() % 2;
				int m4 = rand() % 2;
				int m5 = rand() % 2;
				int m6 = rand() % 2;
				cout << "你获得了:" << endl;
				cout << m1 << "元" << endl;
				cout << m2 << "瓶生命药水" << endl;
				cout << m3 << "瓶防御药水" << endl;
				cout << m4 << "瓶攻击药水" << endl;
				cout << m5 << "瓶经验药水" << endl;
				cout << m6 << "瓶全幅药水" << endl;
				money += m1;
				bag[19] += m2;
				bag[20] += m3;
				bag[21] += m4;
				bag[22] += m5;
				bag[23] += m6;
				_getch();
				a[x][y - 1] = '@';
				a[x][y] = ' ';
				y--;
			}
			else if (a[x][y - 1] == 'S')
			{
				poisonshop();
			}
			else if (a[x][y - 1] == 'B')
			{
				bookshop();
			}
			else if (a[x][y - 1] == 'T')
			{
				NoticeBoard(l, x, y - 1);
			}
			else if (a[x][y - 1] == '0' && l == 10)
			{
				a[x][y] = '0';
				x = 7;
				y = 12;
				a[x][y] = '@';
			}
			else if (a[x][y - 1] == 'X' && l == 12)
			{
				a[x][y] = ' ';
				x = 9;
				y = 49;
				a[x][y] = '@';
			}
			else if (a[x][y - 1] != '#')
			{
				a[x][y - 1] = '@';
				a[x][y] = ' ';
				y -= 1;
			}
			if (l == 9 && x == 4 && y == 12)
			{
				a[x][y - 2] = '@';
				a[x][y] = ' ';
				y -= 2;
			}
		}
		if (ch == 'd')
		{
			if ('0' < a[x][y + 1] && a[x][y + 1] <= '9')
			{
				cout << "你遇到了" << (int)(a[x][y + 1] - '0') << "级怪物，迎战吧！";
				fight("怪物", 1000 * (a[x][y + 1] - '0'), 250 * (a[x][y + 1] - '0'), 10 * (a[x][y + 1] - '0'), 12, 50 * (a[x][y + 1] - '0'));
				if (dead)
				{
					Sleep(1000);
					return 0;
				}
				a[x][y + 1] = '@';
				a[x][y] = ' ';
				y++;
				a[x][y] = ' ';
			}
			else if (a[x][y + 1] == 'I')
			{
				cout << "你是否要退出？" << endl;
				cout << "1确定 2取消" << endl;
				int num;
				cin >> num;
				if (num == 1)
				{
					break;
				}
			}
			else if (a[x][y + 1] == 'o')
			{
				cout << "你通关了" << endl;
				if (nowlevel + 1 == l)
				{
					nowlevel++;
				}
				_getch();
				return 0;
			}
			else if (a[x][y + 1] == 'P')
			{
				int m1 = rand() % 50;
				int m2 = rand() % 2;
				int m3 = rand() % 2;
				int m4 = rand() % 2;
				int m5 = rand() % 2;
				int m6 = rand() % 2;
				cout << "你获得了:" << endl;
				cout << m1 << "元" << endl;
				cout << m2 << "瓶生命药水" << endl;
				cout << m3 << "瓶防御药水" << endl;
				cout << m4 << "瓶攻击药水" << endl;
				cout << m5 << "瓶经验药水" << endl;
				cout << m6 << "瓶全幅药水" << endl;
				money += m1;
				bag[19] += m2;
				bag[20] += m3;
				bag[21] += m4;
				bag[22] += m5;
				bag[23] += m6;
				_getch();
				a[x][y + 1] = '@';
				a[x][y] = ' ';
				y++;
			}
			else if (a[x][y + 1] == 'S')
			{
				poisonshop();
			}
			else if (a[x][y + 1] == 'B')
			{
				bookshop();
			}
			else if (a[x][y + 1] == 'T')
			{
				NoticeBoard(l, x, y + 1);
			}
			else if (a[x][y + 1] == '0' && l == 10)
			{
				a[x][y] = '0';
				x = 7;
				y = 12;
				a[x][y] = '@';
			}
			else if (a[x][y + 1] == 'X' && l == 12)
			{
				a[x][y] = ' ';
				x = 9;
				y = 49;
				a[x][y] = '@';
			}
			else if (a[x][y + 1] != '#')
			{
				a[x][y + 1] = '@';
				a[x][y] = ' ';
				y++;
			}
			if (l == 9 && x == 4 && y == 4)
			{
				a[x][y + 2] = '@';
				a[x][y] = ' ';
				y += 2;
			}
		}
		if (ch == 'w')
		{
			if ('0' < a[x - 1][y] && a[x - 1][y] <= '9')
			{
				cout << "你遇到了" << (int)(a[x - 1][y] - '0') << "级怪物，迎战吧！";
				fight("怪物", 1000 * (a[x - 1][y] - '0'), 250 * (a[x - 1][y] - '0'), 10 * (a[x - 1][y] - '0'), 12, 50 * (a[x - 1][y] - '0'));
				if (dead)
				{
					Sleep(1000);
					return 0;
				}
				a[x - 1][y] = '@';
				a[x][y] = ' ';
				x--;
				a[x][y] = ' ';
			}
			else if (a[x - 1][y] == 'I')
			{
				cout << "你是否要退出？" << endl;
				cout << "1确定 2取消" << endl;
				int num;
				cin >> num;
				if (num == 1)
				{
					break;
				}
			}
			else if (a[x - 1][y] == 'o')
			{
				cout << "你通关了" << endl;
				if (nowlevel + 1 == l)
				{
					nowlevel++;
				}
				_getch();
				return 0;
			}
			else if (a[x - 1][y] == 'P')
			{
				int m1 = rand() % 50;
				int m2 = rand() % 2;
				int m3 = rand() % 2;
				int m4 = rand() % 2;
				int m5 = rand() % 2;
				int m6 = rand() % 2;
				cout << "你获得了:" << endl;
				cout << m1 << "元" << endl;
				cout << m2 << "瓶生命药水" << endl;
				cout << m3 << "瓶防御药水" << endl;
				cout << m4 << "瓶攻击药水" << endl;
				cout << m5 << "瓶经验药水" << endl;
				cout << m6 << "瓶全幅药水" << endl;
				money += m1;
				bag[19] += m2;
				bag[20] += m3;
				bag[21] += m4;
				bag[22] += m5;
				bag[23] += m6;
				_getch();
				a[x - 1][y] = '@';
				a[x][y] = ' ';
				x--;
			}
			else if (a[x - 1][y] == 'S')
			{
				poisonshop();
			}
			else if (a[x - 1][y] == 'B')
			{
				bookshop();
			}
			else if (a[x - 1][y] == 'T')
			{
				NoticeBoard(l, x - 1, y);
			}
			else if (a[x - 1][y] == '0' && l == 10)
			{
				a[x][y] = '0';
				x = 7;
				y = 12;
				a[x][y] = '@';
			}
			else if (a[x - 1][y] == 'X' && l == 12)
			{
				a[x][y] = ' ';
				x = 9;
				y = 49;
				a[x][y] = '@';
			}
			else if (a[x - 1][y] != '#')
			{
				a[x - 1][y] = '@';
				a[x][y] = ' ';
				x -= 1;
			}
		}
		if (ch == 's')
		{
			if (a[x + 1][y] == ' ')
			{
				a[x + 1][y] = '@';
				a[x][y] = ' ';
				x += 1;
			}
			else if ('0' < a[x + 1][y] && a[x + 1][y] <= '9')
			{
				cout << "你遇到了" << (int)(a[x + 1][y] - '0') << "级怪物，迎战吧！";
				fight("怪物", 1000 * (a[x + 1][y] - '0'), 250 * (a[x + 1][y] - '0'), 10 * (a[x + 1][y] - '0'), 12, 50 * (a[x + 1][y] - '0'));
				if (dead)
				{
					Sleep(1000);
					return 0;
				}
				a[x + 1][y] = '@';
				a[x][y] = ' ';
				x++;
				a[x][y] = ' ';
			}
			else if (a[x + 1][y] == 'I')
			{
				cout << "你是否要退出？" << endl;
				cout << "1确定 2取消" << endl;
				int num;
				cin >> num;
				if (num == 1)
				{
					break;
				}
			}
			else if (a[x + 1][y] == 'o')
			{
				cout << "你通关了" << endl;
				if (nowlevel + 1 == l)
				{
					nowlevel++;
				}
				_getch();
				return 0;
			}
			else if (a[x + 1][y] == 'P')
			{
				int m1 = rand() % 50;
				int m2 = rand() % 2;
				int m3 = rand() % 2;
				int m4 = rand() % 2;
				int m5 = rand() % 2;
				int m6 = rand() % 2;
				cout << "你获得了:" << endl;
				cout << m1 << "元" << endl;
				cout << m2 << "瓶生命药水" << endl;
				cout << m3 << "瓶防御药水" << endl;
				cout << m4 << "瓶攻击药水" << endl;
				cout << m5 << "瓶经验药水" << endl;
				cout << m6 << "瓶全幅药水" << endl;
				money += m1;
				bag[19] += m2;
				bag[20] += m3;
				bag[21] += m4;
				bag[22] += m5;
				bag[23] += m6;
				_getch();
				a[x + 1][y] = '@';
				a[x][y] = ' ';
				x++;
			}
			else if (a[x + 1][y] == 'S')
			{
				poisonshop();
			}
			else if (a[x + 1][y] == 'B')
			{
				bookshop();
			}
			else if (a[x + 1][y] == 'T')
			{
				NoticeBoard(l, x + 1, y);
			}
			else if (a[x + 1][y] == '0' && l == 10)
			{
				a[x][y] = '0';
				x = 7;
				y = 12;
				a[x][y] = '@';
			}
			else if (a[x + 1][y] == 'X' && l == 12)
			{
				a[x][y] = ' ';
				x = 9;
				y = 49;
				a[x][y] = '@';
			}
			else if (a[x + 1][y] != '#')
			{
				a[x + 1][y] = '@';
				a[x][y] = ' ';
				x++;
			}
		}
	}
	return 0;
}
int MM()
{
	if (amm == 0)
	{
		int lie = 0;
		cout << "....建议45级打,飘升80级...." << endl;
		cout << "攻击即可获得:" << endl;
		cout << "抽奖券*100 技能书昏昏倒地或技能书铁甲咒 全幅药水*50";
		cout << " 金币*2000 经验石X*50" << endl;
		cout << " 1攻击 2变强后再来" << endl;
		int a;
		cin >> a;
		if (a == 1)
		{
			cout << "你来到了魔法部大门" << endl;
			Sleep(1000);
			cout << "魔法部大门看守:你来这干嘛！" << endl;
			Sleep(1000);
			cout << "1抢劫！ 2办事的。" << endl;
			cin >> a;
			if (a == 1)
				cout << "魔法部大门看守:拦下他！" << endl;
			else
			{
				if (camp)
					cout << "魔法部大门看守:不可能，你是伏地魔的人！" << endl;
				else
				{
					cout << "魔法部大门看守仔细一看。" << endl;
					Sleep(1000);
					cout << "魔法部大门看守:他是哈利波特的人，抓了他问哈利波特下落！" << endl;
				}
			}
			Sleep(1000);
			fight("大门看守", 2000, 200, 20, 0, 1000);
			if (dead)
				return 0;
			fight("大门看守", 2000, 200, 20, 0, 1000);
			if (dead)
				return 0;
			cout << "增加100滴血" << endl;
			health += 100;
			Sleep(1000);
			cout << "你踢开了大门" << endl;
			Sleep(1000);
			cout << "里面的几个雕像活了" << endl;
			Sleep(1000);
			fight("雕像", 10000, 200, 20, 0, 500);
			if (dead)
				return 0;
			fight("雕像", 10000, 200, 20, 0, 500);
			if (dead)
				return 0;
			fight("雕像", 10000, 200, 20, 0, 500);
			if (dead)
				return 0;
			cout << "增加500滴血" << endl;
			health += 500;
			cout << "你杀死了雕像后, 正准备往楼上走" << endl;
			Sleep(1000);
			cout << "突然一群员工跑了过来" << endl;
			Sleep(1000);
			cout << "员工：这是你干你的吗" << endl;
			Sleep(1000);
			cout << "1,撒谎  其他,是！" << endl;
			cin >> a;
			if (a == 1)
			{
				cout << "员工：是谁干的？" << endl;
				Sleep(1000);
				cout << "你随便指了一个员工" << endl;
				Sleep(1000);
				cout << "他！" << endl;
				Sleep(1000);
				cout << "那群员工匆匆跑了过去" << endl;
				Sleep(1000);
				cout << "你赶快跑上楼梯" << endl;
				Sleep(1000);
				lie = 1;
			}
			else
			{
				cout << "员工：干掉他！" << endl;
				Sleep(1000);
				fight("员工", 3000, 200, 100, 14, 1000);
				if (dead)
					return 0;
				fight("员工", 3000, 200, 100, 14, 1000);
				if (dead)
					return 0;
				fight("员工", 3000, 200, 100, 14, 1000);
				if (dead)
					return 0;
				fight("员工", 3000, 200, 100, 15, 1000);
				if (dead)
					return 0;
				fight("员工", 3000, 200, 100, 17, 1000);
				if (dead)
					return 0;
				if (rand() % 3 == 0)
				{
					cout << "你获得了技能书铁甲咒" << endl;
					bag[7]++;
					Sleep(1000);
				}
				cout << "你赶快跑上楼梯" << endl;
				health += 500;
			}
			Sleep(1000);
			cout << "你遇到了副部长" << endl;
			Sleep(1000);
			fight("副部长", 10000, 1000, 100, 20, 3000);
			health += 5000;
			if (dead)
				return 0;
			if (lie)
			{
				cout << "上次的员工跑了过来" << endl;
				Sleep(1000);
				cout << "员工:你，你骗了我们！" << endl;
				Sleep(1000);
				fight("员工", 3000, 200, 100, 14, 1000);
				if (dead)
					return 0;
				fight("员工", 3000, 200, 100, 14, 1000);
				if (dead)
					return 0;
				fight("员工", 3000, 200, 100, 14, 1000);
				if (dead)
					return 0;
				fight("员工", 3000, 200, 100, 15, 1500);
				if (dead)
					return 0;
				fight("员工", 3000, 200, 100, 17, 2000);
				if (dead)
					return 0;
				if (rand() % 3 == 0)
				{
					cout << "你获得了技能书铁甲咒" << endl;
					bag[7]++;
					Sleep(1000);
				}
				health += 500;
			}
			cout << "你遇到了部长";
			fight("部长", 15000, 1500, 150, 20, 4000);
			if (dead)
				return 0;
			cout << "你获得:" << endl;
			cout << "抽奖券*100 技能书昏昏倒地或技能书铁甲咒 全幅药水*50";
			cout << " 金币*2000 经验石X*50" << endl;
			bag[0] += 100;
			bag[8]++;
			bag[23] += 50;
			money += 2000;
			bag[5] += 50;
			amm = 1;
			Sleep(3000);
		}
		else if (a == 2)
			return 0;
		else
		{
			cout << "请勿乱输";
			Sleep(1000);
		}
	}
	else
	{
		cout << "你已占领魔法部 可以进入以下地方" << endl;
		cout << "0,退出 1,泡温泉 2,矿洞" << endl;
		int b;
		cin >> b;
		switch (b)
		{
		case 0:
			break;
		case 1:
			time_t c_start, t_start, c_end, t_end;
			c_start = clock();
			t_start = time(NULL);
			cout << "正在泡温泉 按下任意键停止" << endl;
			_getch();
			c_end = clock();
			t_end = time(NULL);
			cout << "你获得" << (int)difftime(c_end, c_start) / 100 << "元" << endl;
			cout << "你获得" << (int)difftime(c_end, c_start) / 10 << "经验" << endl;
			experience += (int)difftime(c_end, c_start) / 10;
			money += (int)difftime(c_end, c_start) / 100;
			_getch();
			break;
		case 2:
			cout << "你走进矿洞" << endl;
			Sleep(1000);
			ict++;
			if (ict == 5)
				cout << "你不小心靠在墙上,触发了机关" << endl;
			else if (ict > 5)
				cout << "你找到原来触发机关的地方，按下那块岩石，密道又出现了" << endl;
			cout << "0,退出 1,挖矿";
			if (ict > 4)
				cout << " 2,暗道";
			cout << endl;
			int c;
			cin >> c;
			if (c == 1)
				dig();
			else if (c == 2 && ict > 4)
			{
				cout << "你走进暗道" << endl;
				_getch();
				cout << "你发现了一个完全不同的世界，里面充满了怪物" << endl;
				_getch();
				cout << "每去一个地方都有可能遇到他们" << endl;
				_getch();
				cout << "但你有一种直觉，穿过这个森林，就能找到某些东西" << endl;
				_getch();
				MessageBox(0, TEXT("建议 生命>60000 攻击>20000 防御>2000 速度>1000 时来打"), TEXT("重要提示"), MB_OK);
				if (MessageBox(0, TEXT("用 wasd 移动，o出口，I入口，@你"), TEXT("重要提示"), MB_OKCANCEL | MB_ICONINFORMATION) != IDOK)
				{
					MessageBox(0, TEXT("下次再来吧！"), TEXT("重要提示"), MB_OK);
					return 0;
				};
				cout << "开始吧！" << endl;
				maze();
			}
			else
				cout << "请勿乱输" << endl;
			Sleep(1000);
			break;
		}
	}
	return 0;
}
int finalfight(string Hname)
{
	int hisH = 1000000000, hisA = 1000000, hisD = 500000, hisSP = 5000;
	int hfaint = 0, hhurt = 0, hbeat = 0;
	int mfaint = 0, mhurt = 0;
	dead = false;
	int ha = hisA;
	int his = hisA + hisD + hisH;
	while (1)
	{
		if (hfaint > 0)
		{
			if (rand() % 3 == 0)
			{
				cout << "对方使用技能：咒立停！停止了魔咒" << endl;
				hfaint = 1;
			}
			hfaint -= 1;
		}
		if (hbeat == 1)
		{
			if (rand() % 10 == 0)
			{
				cout << "对方一躲，躲过了你的石头" << endl;
				hbeat = 0;
			}
			else
			{
				cout << "对方躲闪不急，石头正好撞在他的鼻子上 扣血50滴" << endl;
				hisH -= 50;
			}
		}
		if (mfaint > 0)
		{
			if (Sl[6])
				mfaint = 0;
			else
				mfaint -= 1;
		}
		if (mhurt > 0)
		{
			if (Sl[6])
				mhurt = 0;
			else
			{
				mhurt -= 1;
				cout << "你的心像被一把刀刺穿了一样 扣血200滴" << endl;
				health -= 200;
			}
		}
		if (mfaint <= 0)
		{
			if (rand() % 3 && Sl[0])
			{
				cout << "你使用技能快快复苏 生命增加200" << endl;
				health += 200;
			}
			if (rand() % 3 && Sl[1])
			{
				cout << "你使用技能铁甲护身 生命增加100 防御增加50" << endl;
				health += 100;
				defense += 50;
			}
			if (rand() % 3 && Sl[2])
			{
				cout << "你使用技能昏昏倒地 " << Hname << "一回合之内不能攻击" << endl;
				hfaint += 1;
			}
			if (rand() % 3 && Sl[3])
			{
				cout << "你使用技能神锋无影 攻击增加200 对方扣血200滴" << endl;
				hisH -= 200;
				attack += 200;
			}
			if (rand() % 3 && Sl[5])
			{
				if (rand() % 10)
				{
					cout << "你使用技能统统石化 " << Hname << "二回合之内不能攻击" << endl;
					hfaint += 2;
				}
				else
				{
					cout << "你使用技能统统石化 " << Hname << "十回合之内不能攻击" << endl;
					hfaint += 10;
				}
			}
			if (rand() % 4 == 0 && Sl[7])
			{
				cout << "你使用技能召唤咒！召唤出石怪跟" << Hname << "战斗" << endl;
				hisH = monsterfight(Hname, hisH, hisA, hisD, 23, hisSP);
				if (hisH < 1)
				{
					cout << "对方死亡" << endl;
					Sleep(1000);
					cout << "全部人都来庆祝你" << endl;
					Sleep(1000);
					cout << "突然，" << Hname << "的魔杖一转，指向了你。" << endl;
					Sleep(1000);
					cout << "里面发出一束红色的光柱" << endl;
					Sleep(1000);
					cout << "你连忙拿魔杖一挡" << endl;
					Sleep(1000);
					cout << "那光柱击中你的魔杖，爆炸了" << endl;
					Sleep(1000);
					cout << "你的魔杖断了" << endl;
					Sleep(1000);
					cout << "你被炸出20多米" << endl;
					Sleep(1000);
					cout << "未完待续..." << endl;
					Sleep(10000);
					return 0;
				}
				if (Sl[0])
				{
					cout << "在对方和石怪的战斗中，你已经恢复了2000生命" << endl;
					if (maxhealth < health + 2000)
						health = maxhealth;
					else
						health += 2000;
				}
			}
			if (rand() % 4 == 0 && Sl[8])
			{
				cout << "你使用技能召唤咒！召唤出石怪跟" << Hname << "战斗" << endl;
			}
			if (rand() % 3 && Sl[9])
			{
				cout << "你使用技能万弹齐发！变出几十块石头" << endl;
				hbeat = 1;
			}
			if (rand() % 3 && Sl[10])
			{
				cout << "你使用技能钻心咒！对方将疼痛5回合" << endl;
				hhurt += 5;
			}
			if (rand() % 3 && Sl[11])
			{
				cout << "魂魄出窍！你使用夺魂咒，企图让" << Hname << "自己攻击自己！" << endl;
				Sleep((rand() % 2000) + 1000);
				cout << Hname << "被你控制了，开始攻击自己" << endl;
				Sleep(700);
				int ran = rand() % 40 - 20;
				if (hisA + ran > hisD)
				{
					cout << "对方发起进攻 自己扣血" << hisH - hisD + ran << "滴 剩余" << hisH - (hisA - hisD + ran) << "滴" << endl;
					hisH -= hisA - hisD + ran;
				}
				else
					cout << "对方发起进攻 自己扣血0滴 剩余" << hisH << "滴" << endl;
			}
			if (rand() % 2 && Sl[12])
			{
				cout << "你使用技能阿瓦达索命 " << Hname << "扣血" << hisH - hisH / 4 << "滴" << endl;
				hisH /= 4;
			}
			Sleep(1000);
			int ran = rand() % 40 - 20;
			if (rand() % 10000 > hisSP)
			{
				if (attack + ran > hisD)
				{
					cout << "你发起进攻 " << Hname << "扣血" << attack - hisD + ran << "滴 剩余" << hisH - (attack - hisD + ran) << "滴" << endl;
					hisH -= attack - hisD + ran;
				}
				else
					cout << "你发起进攻 " << Hname << "扣血0滴 剩余" << hisH << "滴" << endl;
			}
			else
			{
				if (rand() % 2)
					cout << "你一脚踹了过去，但没有踢中" << endl;
				else
				{
					cout << "你一脚踹了过去，但只擦着了腰" << endl;
					if ((attack / 3) + ran > hisD)
					{
						cout << Hname << "扣血" << (attack / 3) + ran - hisD << "滴 剩余" << hisH - ((attack / 3) + ran - hisD) << "滴" << endl;
						hisH -= (attack / 3) + ran - hisD;
					}
					else
						cout << Hname << "扣血0滴 剩余" << hisH << "滴" << endl;
				}
			}
		}
		Sleep(700);
		if (hhurt > 0)
		{
			hhurt -= 1;
			cout << "对方因中了你的钻心咒，正捂着心大叫呢 扣血200滴" << endl;
			hisH -= 200;
		}
		if (hisH <= 0)
		{
			if (rand() % 3 == 0)
			{
				cout << "对方发动技能：恢复如初 满血复活" << endl;
				hisH = ha;
				Sleep(1000);
			}
			else
			{
				cout << "对方死亡" << endl;
				Sleep(1000);
				cout << "全部人都来庆祝你" << endl;
				Sleep(1000);
				cout << "突然，" << Hname << "的魔杖一转，指向了你。" << endl;
				Sleep(1000);
				cout << "里面发出一束红色的光柱" << endl;
				Sleep(1000);
				cout << "你连忙拿魔杖一挡" << endl;
				Sleep(1000);
				cout << "那光柱击中你的魔杖，爆炸了" << endl;
				Sleep(1000);
				cout << "你的魔杖断了" << endl;
				Sleep(1000);
				cout << "你被炸出20多米" << endl;
				Sleep(1000);
				cout << "未完待续..." << endl;
				Sleep(10000);
				return 0;
			}
		}
		if (rand() % 3 == 0)
		{
			cout << "对方发动技能：快快复苏  生命加200" << endl;
			hisH += 200;
		}
		if (rand() % 3 == 0)
		{
			cout << "对方发动技能：盔甲护身  生命加50 防御增加50" << endl;
			hisH += 50;
			hisD += 50;
		}
		if (rand() % 3 == 0)
		{
			cout << "对方使用技能神锋无影 攻击增加200 扣血200滴" << endl;
			health -= 200;
			hisA += 200;
		}
		if (rand() % 3 == 0)
		{
			cout << "对方使用技能昏昏倒地 " << name << "一回合之内不能攻击" << endl;
			mfaint += 1;
		}
		if (rand() % 3 == 0)
		{
			if (rand() % 10)
			{
				cout << "对方使用技能统统石化 " << name << "二回合之内不能攻击" << endl;
				mfaint += 2;
			}
			else
			{
				cout << "对方使用技能统统石化 " << name << "十回合之内不能攻击" << endl;
				mfaint += 10;
			}
		}
		if (rand() % 3 == 0)
		{
			cout << "对方使用技能阿瓦达索命 " << name << "扣血" << health - health / 4 << "滴" << endl;
			health /= 4;
		}
		Sleep(1000);
		if (hfaint <= 0)
		{
			int ran = rand() % 40 - 20;
			if (rand() % 10000 > speed)
			{
				if (hisA + ran > defense)
				{
					cout << Hname << "发起进攻 "
						 << "你扣血" << hisA - defense + ran << "滴 剩余" << health - (hisA - defense + ran) << "滴" << endl;
					health -= hisA - defense + ran;
				}
				else
					cout << Hname << "发起进攻 "
						 << "你扣血0滴 剩余" << health << "滴" << endl;
			}
			else
			{
				if (rand() % 2)
					cout << Hname << "一脚踹了过来，但没有踢中" << endl;
				else
				{
					if ((hisA / 3) + ran > hisD)
					{
						cout << Hname << "发起进攻 你扣血" << (hisA / 3) + ran - defense << "滴 剩余" << health - ((hisA / 3) + ran - defense) << "滴" << endl;
						health -= ((hisA / 3) + ran - defense);
					}
					else
						cout << Hname << "发起进攻 "
							 << "你扣血0滴 剩余" << health << "滴" << endl;
				}
			}
			Sleep(1000);
			if (health <= 0)
			{
				if (Sl[6] && rand() % 2)
				{
					cout << "你发动技能：恢复如初 满血复活" << endl;
					health = maxhealth;
					Sleep(1000);
				}
				else
				{
					cout << "你死亡";
					health = 20;
					dead = true;
					return 0;
				}
			}
		}
	}
	return 0;
}
int buyitem(int num, int m)
{
	if (money < m)
		cout << "没钱，打出去！" << endl;
	else
	{
		cout << "购买成功" << endl;
		wand[num + 23]++;
		money -= m;
		if (ane == 1)
			D_Of_C++;
		if (ane1 == 1)
			D_Of_C1 += m;
	}
	Sleep(1000);
	return 0;
}
int itemshop()
{
	system("system");
	cout << "欢迎来到材料店" << endl;
	cout << "这里有许多可以卖的" << endl;
	cout << "1，猫狸子胡须   1000元" << endl;
	cout << "2，媚娃头发     1000元" << endl;
	cout << "3，形水怪的鬃毛 1000元" << endl;
	cout << "4，龙心腱       1000元" << endl;
	cout << "5，雷鸟尾羽     1000元" << endl;
	cout << "6，凤凰羽毛     1000元" << endl;
	cout << "7，独角兽尾毛   1000元" << endl;
	cout << "8，龙神经       1000元" << endl;
	cout << "9，夜骐的尾羽   1000元" << endl;
	cout << "按0退出" << endl;
	int con = 0;
	cin >> con;
	switch (con)
	{
	case 1:
		buyitem(1, 1000);
	case 2:
		buyitem(2, 1000);
	case 3:
		buyitem(3, 1000);
	case 4:
		buyitem(4, 1000);
	case 5:
		buyitem(5, 1000);
	case 6:
		buyitem(6, 1000);
	case 7:
		buyitem(7, 1000);
	case 8:
		buyitem(8, 1000);
	case 9:
		buyitem(9, 1000);
	case 0:
		return 0;
	}
}
int main()
{
	int isbreak;
	isbreak = false;
	if (MessageBox(0, TEXT("我是你爹，我想c爆你"), TEXT("重要提示"), MB_OKCANCEL | MB_ICONINFORMATION) != IDOK)
	{
		MessageBox(0, TEXT("既然你不同意，那就别玩了"), TEXT("重要提示"), MB_OK);
		return 0;
	};
	srand((unsigned)time(NULL));
	cout << "                              1.2.9 \n";
	cout << "      MagicWorld--HarryPotter       \n";
	cout << "                                    \n";
	cout << "         / >                        \n";
	cout << "        /    >          /           \n";
	cout << "       < _____ >       /            \n";
	cout << "        |-O--O-|      /             \n";
	cout << "       /   == - .    /              \n";
	cout << "     /           . [  ]             \n";
	cout << "       /      /` ___/               \n";
	cout << "                                    \n";
	cout << "                             by evan\n";
	cout << "输入‘start’开始游戏                  \n";
	string start;
	cin >> start;
	for (int i = 8; i < 100; i++)
		wandname[i] = "1";
	if (start == "start")
	{
		int i;
		system("system");
		for (i = 0; i < 11; i++)
		{
			if (i == 10)
			{
				system("system");
				cout << "加载成功" << endl;
				Sleep(1200);
				system("system");
				break;
			}
			cout << "loading..." << endl
				 << "--------------------------" << endl
				 << "   ";
			for (int j = 0; j <= i % 5; j++)
				cout << "+==+";
			cout << "   " << endl
				 << "--------------------------" << endl;
			switch (rand() % 4)
			{
			case 0:
				cout << "打怪是升级和提升战力的好方法。" << endl;
				break;
			case 1:
				cout << "开始游戏时记得选择阵营。" << endl;
				break;
			case 2:
				cout << "退出时要保存。" << endl;
				break;
			case 3:
				cout << "新手开始游戏时会有3瓶经验药水1张抽奖券。" << endl;
				break;
			}
			Sleep(750);
			system("system");
		}
		while (1)
		{
			isbreak = false;
			cout << "1,登录 2,注册";
			int a;
			cin >> a;
			if (a == 1)
				login();
			else
				Reg();
			while (1)
			{
				if (isbreak)
				{
					break;
				}
				system("system");
				cout << "魔法人士：" << name << endl;
				cout << "势力：";
				if (camp)
					cout << "伏地魔" << endl;
				else
					cout << "哈利波特" << endl;
				cout << "生命:" << health << "/" << maxhealth << endl;
				cout << "攻击:" << attack << endl;
				cout << "防御:" << defense << endl;
				cout << "速度:" << speed << endl;
				cout << "等级:" << level << endl;
				cout << "经验:" << experience << "/" << level * 100 << endl;
				cout << "金币:" << money << endl;
				cout << "1,魔法部(攻击即可占领) 2,大街(杀人/阻止食死徒) 3,";
				if (camp)
					cout << "霍格沃茨(哈利波特不在) ";
				else
					cout << "伏地魔总部(伏地魔不在) ";
				cout << "4,霍格沃茨(最后战场) 5,奥利凡德魔杖商店 6,抽奖 7,经验石店 8,背包 9,工厂 10,材料店 11,任务 12,终极任务 13,副本 14,保存 ";
				if (camp)
					cout << "15, 医疗兵（伏地魔的）";
				else
					cout << "15, 庞弗雷女士 ";
				cout << "16,改变参数（测试专用 需要密码） 17,设置 18,登出" << endl;
				cin >> a;
				switch (a)
				{
				case 1:
					MM();
					break;
				case 2:
					street();
					break;
				case 3:
					for (int i = 1; i < 100; i++)
					{
						cout << "|";
						for (int j = 0; j < 10 && i < 100; j++, i++)
						{
							if (nowlevel + 1 < i)
								cout << " " << i << " |";
							else
								cout << ":" << i << ":|";
						}
						cout << endl;
					}
					int num;
					cin >> num;
					if (nowlevel + 1 < num)
						cout << "你未解锁这关" << endl;
					else
						checkpoint(num);
					Sleep(1000);
					break;
				case 4:
					if (camp)
					{
						if (f)
							finalfight("哈利·波特");
						else
							cout << "你需要先寻找哈利波特的下落" << endl;
					}
					else
					{
						if (f)
							finalfight("伏地魔");
						else
							cout << "你需要先寻找伏地魔的下落" << endl;
					}
					Sleep(1000);
					break;
				case 5:
					cout << "1 柳条独角兽尾毛魔杖   100元" << endl;
					cout << "2 胡桃木龙神经魔杖     200元" << endl;
					cout << "3 鹅耳枥木魔杖        550元" << endl;
					cout << "4 柳条魔杖            1200元" << endl;
					cout << "5 花心木魔杖          3650元" << endl;
					cout << "6 冬青木凤凰羽毛魔杖   5780元" << endl;
					cout << "7 紫杉木凤凰羽毛魔杖   7120元" << endl;
					cout << "8 老魔杖              50000元" << endl;
					cout << "0 退出              0元" << endl;
					int b;
					cin >> b;
					switch (b)
					{
					case 1:
						buywand(6, 100);
						system("system");
						break;
					case 2:
						buywand(7, 200);
						system("system");
						break;
					case 3:
						buywand(8, 550);
						system("system");
						break;
					case 4:
						buywand(9, 1200);
						system("system");
						break;
					case 5:
						buywand(10, 3650);
						system("system");
						break;
					case 6:
						buywand(11, 5780);
						system("system");
						break;
					case 7:
						buywand(12, 7120);
						system("system");
						break;
					case 8:
						buywand(13, 50000);
						system("system");
						break;
					default:
						break;
					}
					break;
				case 6:
					LD();
					break;
				case 7:
					cout << "1 经验石R      100元    100经验" << endl;
					cout << "2 经验石SR     200元    250经验" << endl;
					cout << "3 经验石SSR    400元    500经验" << endl;
					cout << "4 经验石SSS    1000元   1200经验" << endl;
					cout << "5 经验石X      2000元   2500经验" << endl;
					cout << "0 退出         0元      0经验" << endl;
					int c;
					cin >> c;
					switch (c)
					{
					case 1:
						buy(1, 100);
						system("system");
						break;
					case 2:
						buy(2, 200);
						system("system");
						break;
					case 3:
						buy(3, 550);
						system("system");
						break;
					case 4:
						buy(4, 1200);
						system("system");
						break;
					case 5:
						buy(5, 3650);
						system("system");
						break;
					default:
						break;
					}
					break;
				case 8:
					cout << "1,查看魔杖 2,查看药水 3,查看经验石 4,学习技能" << endl;
					cin >> b;
					if (b == 1)
						w();
					else if (b == 2)
						p();
					else if (b == 3)
						e();
					else if (b == 4)
						s();
					else
					{
						cout << "请勿乱输" << endl;
						Sleep(1000);
					}
					break;
				case 9:
					int material1, material2, mn1, mn2;
					cout << "1,制作 2,查看材料";
					cin >> material1;
					if (material1 == 1)
					{
						cout << "你要用什么杖芯？" << endl;
						for (int ij = 0; ij < 9; ij++)
							cout << ij + 1 << "," << Material1name[ij] << " " << bag[ij + 24] << "个" << endl;
						cin >> material1;
						cout << "几个？" << endl;
						cin >> mn1;
						cout << "你要用什么木材？" << endl;
						for (int ij = 0; ij < 10; ij++)
							cout << ij + 1 << "," << Material2name[ij] << " " << bag[ij + 33] << "个" << endl;
						cin >> material2;
						cout << "几个？" << endl;
						cin >> mn2;
						make(material1 + 23, material2 + 32, mn1, mn2);
						break;
					}
					else if (material1 == 2)
					{
						cout << "杖芯：" << endl;
						for (int ij = 0; ij < 9; ij++)
							cout << ij + 1 << "," << Material1name[ij] << " " << bag[ij + 24] << "个" << endl;
						cout << "木材：" << endl;
						for (int ij = 0; ij < 10; ij++)
							cout << ij + 1 << "," << Material2name[ij] << " " << bag[ij + 33] << "个" << endl;
						_getch();
					}
					else
						cout << "请勿乱输";
					break;
				case 10:
					itemshop();
					break;
				case 11:
					if (xy == 1)
					{
						if (ane == 0)
							cout << "再闯 1 关副本";
						else if (ane == 1)
							cout << "买两件商品";
						else if (ane == 2)
							cout << "回血一次";
						else if (ane == 3)
							cout << "杀死10个人";
						cout << "(" << D_Of_C << "/" << OK << ")" << endl;
						if (D_Of_C >= OK)
						{
							cout << "任务完成！！";
							maxhealth += 200;
							health += 200;
							defense += 20;
							xy = 0;
							bag[43]++;
						}
						Sleep(1000);
					}
					else
					{
						ane = rand() % 4;
						D_Of_C = 0;
						xy = 1;
						if (ane == 0)
						{
							cout << "再闯 1 关副本";
							OK = 1;
						}
						else if (ane == 1)
						{
							cout << "买两件商品";
							OK = 2;
						}
						else if (ane == 2)
						{
							cout << "回血一次";
							OK = 1;
						}
						else if (ane == 3)
						{
							cout << "杀死10个人";
							OK = 10;
						}
						Sleep(1000);
					}
					break;
				case 12:
					if (xy1 == 1)
					{
						if (ane1 == 0)
						{
							if (camp)
								cout << "杀死1个邓布利多";
							else
								cout << "杀死1个纳尼吉";
						}
						else if (ane1 == 1)
							cout << "消耗5000元";
						else if (ane1 == 2)
						{
							if (camp)
								cout << "杀死5个穆迪";
							else
								cout << "杀死5个卢修斯·马尔福";
						}
						else if (ane1 == 3)
							cout << "杀死100个生物";
						else if (ane1 == 4)
							cout << "再升10级";
						cout << "(" << D_Of_C1 << "/" << OK1 << ")" << endl;
						if (D_Of_C1 >= OK1)
						{
							cout << "任务完成！！" << endl;
							xy1 = 0;
							cout << "增加500元 攻击力+10 防御力+10 生命+500" << endl;
							money += 500;
							attack += 200;
							health += 1000;
							maxhealth += 1000;
							defense += 150;
							bag[43] += 5;
						}
						Sleep(1000);
					}
					else
					{
						ane1 = rand() % 5;
						D_Of_C1 = 0;
						xy1 = 1;
						if (ane1 == 0)
						{
							if (camp)
								cout << "杀死1个邓布利多";
							else
								cout << "杀死1个纳尼吉";
							OK1 = 1;
						}
						else if (ane1 == 1)
						{
							cout << "消耗5000元";
							OK1 = 5000;
						}
						else if (ane1 == 2)
						{
							if (camp)
								cout << "杀死5个穆迪";
							else
								cout << "杀死5个卢修斯·马尔福";
							OK1 = 5;
						}
						else if (ane1 == 3)
						{
							cout << "杀死100个生物";
							OK1 = 100;
						}
						else if (ane1 == 4)
						{
							cout << "再升10级";
							OK1 = 10;
						}
						Sleep(1000);
					}
					break;
				case 13:
					cout << "1 金钱副本" << LE1 << "级  2 经验副本" << LE2 << "级" << endl;
					int y;
					cin >> y;
					if (y == 1)
					{
						for (int i = 0; i < LE1 % 5; i++)
						{
							if (rand() % 3 == 0)
								fight2("木人桩", 1500, 100, 10, 0, 1000);
							else if (rand() % 3 == 1)
								fight2("沙包", 3000, 50, 20, 0, 1000);
							else
								fight2("木板", 1000, 100, 10, 0, 1000);
							if (dead)
								break;
						}
						for (int i = 0; i < (LE1 / 5) % 25; i++)
						{
							if (dead)
								break;
							if (rand() % 3 == 0)
								fight2("石人桩(这有吗)", 3000, 200, 20, 0, 2000);
							else if (rand() % 3 == 1)
								fight2("石包(这有吗)", 6000, 100, 60, 0, 2000);
							else
								fight2("石板", 3000, 300, 30, 0, 2000);
						}
						for (int i = 0; i < (LE1 / 25) % 125; i++)
						{
							if (dead)
								break;
							if (rand() % 3 == 0)
								fight2("铁人桩(这有吗)", 6000, 400, 40, 0, 4000);
							else if (rand() % 3 == 1)
								fight2("铁包(这有吗)", 12000, 200, 120, 0, 4000);
							else
								fight2("铁板", 6000, 400, 40, 0, 4000);
						}
						for (int i = 0; i < (LE1 / 125) % 625; i++)
						{
							if (dead)
								break;
							if (rand() % 3 == 0)
								fight2("金人桩(这有吗)", 12000, 800, 80, 0, 6500);
							else if (rand() % 3 == 1)
								fight2("金包(这有吗)", 24000, 400, 240, 0, 6500);
							else
								fight2("金板", 12000, 800, 80, 0, 6500);
						}
						if (!dead)
						{
							LE1++;
							if (ane == 0)
								D_Of_C++;
						}
					}
					if (y == 2)
					{
						for (int i = 0; i < LE2 % 5; i++)
						{
							if (rand() % 3 == 0)
								fight1("木人桩", 1500, 100, 10, 0, 1000);
							else if (rand() % 3 == 1)
								fight1("沙包", 3000, 50, 20, 0, 1000);
							else
								fight1("木板", 1000, 100, 10, 0, 1000);
							if (dead)
								break;
						}
						for (int i = 0; i < (LE2 / 5) % 25; i++)
						{
							if (dead)
								break;
							if (rand() % 3 == 0)
								fight1("石人桩(这有吗)", 3000, 200, 20, 0, 1000);
							else if (rand() % 3 == 1)
								fight1("石包(这有吗)", 6000, 100, 60, 0, 1000);
							else
								fight1("石板", 3000, 300, 30, 0, 1000);
						}
						for (int i = 0; i < (LE2 / 25) % 125; i++)
						{
							if (dead)
								break;
							if (rand() % 3 == 0)
								fight1("铁人桩(这有吗)", 6000, 400, 40, 0, 4000);
							else if (rand() % 3 == 1)
								fight1("铁包(这有吗)", 12000, 200, 120, 0, 4000);
							else
								fight1("铁板", 6000, 400, 40, 0, 4000);
						}
						for (int i = 0; i < (LE2 / 125) % 625; i++)
						{
							if (dead)
								break;
							if (rand() % 3 == 0)
								fight1("金人桩(这有吗)", 12000, 800, 80, 0, 6500);
							else if (rand() % 3 == 1)
								fight1("金包(这有吗)", 24000, 400, 240, 0, 6500);
							else
								fight1("金板", 12000, 800, 80, 0, 6500);
						}
						if (!dead)
						{
							LE2++;
							if (ane == 0)
								D_Of_C++;
						}
					}
					break;
				case 14:
					save();
					cout << "保存成功！";
					Sleep(1000);
					break;
				case 15:
					Hos();
					Sleep(1000);
					break;
				case 16:
					int pw;
					cout << "密码：";
					cin >> pw;
					if (pw == 1212)
					{
						cout << "0~42,改变背包 43,金币 44,等级 45,经验 46,生命 47,防御 48,攻击 49,最大生命 50,进入魔法部权力(0没有 1有) 51,速度" << endl;
						int num1, num2;
						cout << "几号：";
						cin >> num1;
						cout << "改变成：";
						cin >> num2;
						if (num1 <= 42)
							bag[num1] = num2;
						else
						{
							switch (num1)
							{
							case 43:
								money = num2;
								break;
							case 44:
								level = num2;
								break;
							case 45:
								experience = num2;
								break;
							case 46:
								health = num2;
								break;
							case 47:
								defense = num2;
								break;
							case 48:
								attack = num2;
								break;
							case 49:
								maxhealth = num2;
								break;
							case 50:
								amm = num2;
								break;
							case 51:
								speed = num2;
								break;
							default:
								break;
							}
						}
						levelup();
						cout << "改变成功";
					}
					else
						cout << "密码错误" << endl;
					Sleep(1000);
					break;
				case 17:
					cout << "1,关卡攻略 2,关卡功能" << endl;
					int xd;
					cin >> xd;
					if (xd == 1)
						system("start https://paste.ubuntu.com/p/2YQBCmYvSb/");
					if (xd == 2)
					{
						cout << "我们先介绍一下图标" << endl;
						cout << "╔═══╗  ╔═══╗  ╔═══╗  ╔═══╗" << endl;
						cout << "║ @ ║  ║ I ║  ║ o ║  ║ # ║" << endl;
						cout << "╚═══╝  ╚═══╝  ╚═══╝  ╚═══╝" << endl;
						cout << "你自己   出口    入口    墙" << endl;
						cout << "╔═══╗  ╔═══╗  ╔═══╗  ╔═══╗" << endl;
						cout << "║ 1 ║  ║ 2 ║  ║ 3 ║  ║ 4 ║" << endl;
						cout << "╚═══╝  ╚═══╝  ╚═══╝  ╚═══╝" << endl;
						cout << "1级怪   2级怪   3级怪  4级怪" << endl;
						cout << "命1000 命2000  命3000 命4000" << endl;
						cout << "攻250  攻500   攻750  攻1000" << endl;
						cout << "防10   防20    防30   防40" << endl;
						cout << "速50   速100   速150  速200" << endl;
						cout << "╔═══╗  ╔═══╗  ╔═══╗  ╔═══╗" << endl;
						cout << "║ 5 ║  ║ 6 ║  ║ 7 ║  ║ 8 ║" << endl;
						cout << "╚═══╝  ╚═══╝  ╚═══╝  ╚═══╝" << endl;
						cout << "5级怪   6级怪   7级怪  8级怪" << endl;
						cout << "命5000 命6000  命7000 命8000" << endl;
						cout << "攻1250 攻1500  攻1750 攻2000" << endl;
						cout << "防50   防60    防70   防80" << endl;
						cout << "速250  速300   速350  速400" << endl;
						cout << "╔═══╗  ╔═══╗  ╔═══╗  ╔═══╗" << endl;
						cout << "║ 9 ║  ║ S ║  ║ B ║  ║ T ║" << endl;
						cout << "╚═══╝  ╚═══╝  ╚═══╝  ╚═══╝" << endl;
						cout << "9级怪  药水商店  书店   告示牌" << endl;
						cout << "命9000" << endl;
						cout << "攻2250" << endl;
						cout << "防90" << endl;
						cout << "速450" << endl;
						cout << "╔═══╗" << endl;
						cout << "║ X ║" << endl;
						cout << "╚═══╝" << endl;
						cout << "传送机" << endl;
						cout << "输入图标了解详细，0退出" << endl;
						string st;
						cin >> st;
						if (st == "@")
							system("start https://paste.ubuntu.com/p/cdJPnhXddT/");
						else if (st == "I" || st == "i")
							system("start https://paste.ubuntu.com/p/h5npMzvDBX/");
						else if (st == "o" || st == "O")
							system("start https://paste.ubuntu.com/p/By6Fdyq9wq/");
						else if (st == "#")
							system("start https://paste.ubuntu.com/p/DswXYhVGFn/");
						else if (st <= "9" && st >= "1")
							system("start https://paste.ubuntu.com/p/4vZDjY7fX4/");
						else if (st == "S" || st == "s")
							system("start https://paste.ubuntu.com/p/SvSTDGrcD3/");
						else if (st == "B" || st == "b")
							system("start https://paste.ubuntu.com/p/MMqwYn63N9/");
						else if (st == "T" || st == "t")
							system("start https://paste.ubuntu.com/p/mXgfbyhGGJ/");
						else if (st == "X" || st == "x")
							system("start https://paste.ubuntu.com/p/M6svDYryGt/");
						else if (st == "0")
							;
						else
							cout << "请勿乱输" << endl;
						Sleep(1000);
					}
					break;
				case 18:
					isbreak = true;
				}
				levelup();
			}
		}
	}
}
