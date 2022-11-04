// 5.4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;
double S0(const int K, const int N)
{
	double s = 0;
	for (int k = 1; k <= N; k++)
		s += 1+sqrt(1+k*k)/(k*k);
	return s;
}
double S1(const int K, const int N, const int k)
{
	if (k > N)
		return 0;
	else
		return 1 + sqrt(1 + k * k) / (k * k) + S1(K, N, k + 1);
}
double S2(const int K, const int N, const int k)
{
	if (k < K)
		return 0;
	else
		return 1 + sqrt(1 + k * k) / (k * k) + S2(K, N, k - 1);
}
double S3(const int K, const int N, const int k, double t)
{
	t = t + 1 + sqrt(1 + k * k) / (k * k);
	if (k >= N)
		return t;
	else
		return S3(K, N, k + 1, t);
}
double S4(const int K, const int N, const int k, double t)
{
	t = t + 1 + sqrt(1 + k * k) / (k * k);
	if (k <= K)
		return t;
	else
		return S4(K, N, k - 1, t);
}

int main()
{
	int K, N;
	cout << "K = "; cin >> K;
	cout << "N = "; cin >> N;
	cout << "(iter) S0 = " << S0(K, N) << endl;
	cout << "(rec up ++) S1 = " << S1(K, N, K) << endl;
	cout << "(rec up --) S2 = " << S2(K, N, N) << endl;
	cout << "(rec down ++) S3 = " << S3(K, N, K, 0) << endl;
	cout << "(rec down --) S4 = " << S4(K, N, N, 0) << endl;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
