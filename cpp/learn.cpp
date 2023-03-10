#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int gcd (int a, int b) {
    if (b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

int main () {
    int a, b, c;
    cin >> a >> b >> c;
    int num1, num2;
    num1 = (a > b ? a : b) > c ? (a > b ? a : b) : c;
    num2 = (a < b ? a : b) < c ? (a < b ? a : b) : c;
    int tmp = gcd(num1, num2);
    cout << num2 / tmp << "/" << num1 / tmp;
}

void Product_Max () {
    int n = 0, m = 0;
    cin >> n >> m;
    int a = n / m;
    int b = n % m;
    for (int i = 0; i < a - b + 1; i++) {
        cout << a << " ";
    }
    for (int i = 0; i < b; i++) {
        cout << a + 1 << " ";
    }   
}

// 完全平方数是指一个数可以分解为某个因数的平方

void Mc_Ex () {
        int times = 0, level = 0;
    long long ex = 0;
    float hp = 10;
    cin >> times;
    float tmp1;
    int tmp2;
    for (int i = 0; i < times; i++) {
        cin >> tmp1 >> tmp2;
        hp -= tmp1;
        if (hp > 10) {
            hp = 10;
        }
        if (hp <= 0) {
            break;
        }
        ex += tmp2;
    }
    for (int i = 0;;i++) {
        ex -= pow(2, i);
        level ++;
        if (ex < 0) {
            ex += pow(2, i);
            level --;
            cout << level << " " << ex;
            break;
        } else if (ex == 0) {
            cout << level << " " << ex;
            break;
        }
    }
}

// void Rects_nested_Rects () {
//     int width, height, times, key;
//     cin >> width >> height >> times >> key;
//     int arr[width][height][2] = {0};
//     for (int i = 0; i < width; i++) {
//         for (int j = 0; j < height; j++) {
//             arr[i][j][1] = 0;
//             arr[i][j][0] = 0;
//         }
//     }
//     for (int i = 0; i < times; i++) {
//         int x1, y1, x2, y2;
//         cin >> x1 >> y1 >> x2 >> y2;
//         for (int j = x1 - 1; j < x2; j ++) {
//             for (int k = y1 - 1; k < y2; k++) {
//                 arr[j][k][0] = i + 1;
//                 arr[j][k][1] += 1;
//             }
//         }
//     }
//     string s;
//     for (int i = 0; i < key; i++) {
//         string tmp;
//         int x, y;
//         cin >> x >> y;
//         if (arr[x - 1][y - 1][1] == 0) {
//             s += "N\n";
//         } else {
//             s += "Y " + to_string(arr[x - 1][y - 1][1]) + " " + to_string(arr[x - 1][y - 1][0]) + "\n";
//         }
//     }
//     cout << s;
// }

void Mc_Torch () {
    // 最大矩阵为100x100, 直接取104x104矩阵保证n无论多大都不会有index溢出现象
    // 从 1 到 1 + n + 2
    // 0 1 2 3 4 5 6 7 8
    //     * * * *   
    int size, num1, num2, x, y;
    int cube[104][104] = {0};
    cin >> size >> num1 >> num2;
    for (int i = 0; i < num1; i++) {
        cin >> x >> y;
        cube[x + 1][y + 1] = 1;
        cube[x + 1][y + 2] = 1;
        cube[x + 1][y + 3] = 1;
        cube[x + 1][y] = 1;
        cube[x + 1][y - 1] = 1;
        cube[x][y + 1] = 1;
        cube[x - 1][y + 1] = 1;
        cube[x + 2][y + 1] = 1;
        cube[x + 3][y + 1] = 1;
        cube[x + 2][y + 2] = 1;
        cube[x][y] = 1;
        cube[x + 2][y] = 1;
        cube[x][y + 2] = 1;
    }
    for (int i = 0; i < num2; i++) {
        cin >> x >> y;
        for (int m = 0; m < 5; m++) {
            for (int n = 0; n < 5; n++) {
                cube[x + m - 1][y + n - 1] = 1;
            }
        }
    }
    int count = 0;
    for (int i = 2; i < 2 + size; i++) {
        for (int j = 2; j < 2 + size; j++) {
            if (!cube[i][j]) {
                // cout << "x" << " ";
                count ++;
            } 
            // else {
            //     cout << "*" << " ";
            // }
        }
        // cout << endl;
    }
    cout << count;
}

// 高精度减法的思路是先比较两个数字的大小，然后确定结果的正负之后，大数字减小数字

// 高精度除法则是模拟除法竖式运算，保留商，余数乘以10加上下一位继续进行除法操作。（大数/小数）

void High_Precision_Factorial_Addition () {
    int ans[100] = {0};
    int num = 0;
    cin >> num;
    for (int n = 1; n <= num; n++) {
        // 定义变量装每次计算结果和进位信息
        int tmp = 0, carry = 0;
        // 先计算阶乘的结果
        int jc[100] = {0};
        jc[99] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 99; j >= 0; j--) {
                tmp = jc[j] * i + carry;
                jc[j] = tmp % 10;
                carry = tmp / 10;
            }
            carry = 0;
            tmp = 0;
        }
        // 将阶乘的结果累加到结果数组中去
        tmp = 0;
        carry = 0;
        for (int i = 99; i >= 0; i--) {
            tmp = ans[i] + jc[i] + carry;
            ans[i] = tmp % 10;
            carry = tmp / 10;
        }
    }
    
    bool flag = false;
    for (int i = 0; i < 100; i++) {
        if (flag) {
            cout << ans[i];
        } else {
            if (ans[i] != 0) {
                cout << ans[i];
                flag = true;
            }
        }
    }
}

void Nine_Key_Press () {
    string s;
    int ans = 0;
    getline(cin, s);
    for (unsigned int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == ' ' || c == 'a' || c == 'd' || c == 'g' || c == 'j' || c == 'm' || c == 'p' || c == 't' || c == 'w') {
            ans += 1;
        }
        if (c == 'b' || c == 'e' || c == 'h' || c == 'k' || c == 'n' || c == 'q' || c == 'u' || c == 'x') {
            ans += 2;
        }
        if (c == 'c' || c == 'f' || c == 'i' || c == 'l' || c == 'o' || c == 'r' || c == 'v' || c == 'y') {
            ans += 3;
        }
        if (c == 's' || c == 'z' ) {
            ans += 4;
        }
    }
    cout << ans;  
}

void Match_Bracket () {
    string s;
    cin >> s;
    int l = 0;
    for (unsigned int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            l++;
        }
        if (s[i] == ')') {
            l--;
        }
        if (l < 0) {
            break;
        }
    }
    if (l == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}

void Rabbit_list () {
    double ans = 0;
    int n = 0;
    cin >> n;
    ans = (pow((1 + sqrt(5)) / 2, n) - pow((1 - sqrt(5)) / 2, n)) / sqrt(5);
    printf("%.2lf\n", ans);
}

void Distance_to_Circle () {
    int nums, x1, y1, x2, y2, ans = 0;
    int xs[51] = {0};
    int ys[51] = {0};
    int rs[51] = {0};
    cin >> nums;
    for (int i = 0; i < nums; i++) {
        cin >> xs[i];
    }
    for (int i = 0; i < nums; i++) {
        cin >> ys[i];
    }
    for (int i = 0; i < nums; i++) {
        cin >> rs[i];
    }
    cin >> x1 >> y1 >> x2 >> y2;
    float d1 = 0, d2 = 0;
    for (int i = 0; i < nums; i++) {
        d1 = sqrt(pow(x1 - xs[i], 2) + pow(y1 - ys[i], 2));
        d2 = sqrt(pow(x2 - xs[i], 2) + pow(y2 - ys[i], 2));
        if ((d1 < rs[i] && d2 > rs[i]) || (d1 > rs[i] && d2 < rs[i])) {
            ans++;
        }
    }
    cout << ans;
}

// void Infectious_Disease_Main () {
//     long long ans;
//     long long plus, times;
//     cin >> plus >> times;
//     ans = Infectious_Disease (plus, times);
//     cout << ans;
// }

long long  Infectious_Disease (long long plus, long long times) {
    if (times == 0) {
        return 1;
    } else {
        return (Infectious_Disease (plus, times - 1)) * (plus + 1);
    }
}

int test (long long plus, long long times) {
    long long ans = 1;
    for (int i = 0; i < times; i++) {
            ans = ans * (plus + 1);
        }
    return ans;
}



void Calc_Time () {
    int h1 = 0, h2 = 0, m1 = 0, m2 = 0, num = 0;
    long long s1 = 0, s2 = 0;
    char c;
    long long ans;
    cin >> h1 >> c >> m1 >> c >> s1;
    cin >> h2 >> c >> m2 >> c >> s2;
    cin >> num;
    s1 += (h1 * 3600 + m1 * 60);
    s2 += (h2 * 3600 + m2 * 60);
    ans = (s2 - s1) * num;
    cout << ans;
}

void Consecutive_Sum () {
    int n, m, ans = 10000000, tmp = 0;
    cin >> n >> m;
    int arr[100001] = {0};
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i <= n - m; i++) {
        for (int j = 0; j < m; j++) {
            tmp += arr[i + j];
        }
        if (ans > tmp) {
            ans = tmp;
        }
        tmp = 0;
    }
    cout << ans;
}

void Pascal_parise () {
        char c, tmp, num;
	int n1 = 0, n2 = 0, n3 = 0;
	while (cin >> c >> tmp >> tmp >> num >> tmp) {
		switch (c) {
			case 'a':
				if (num == 'b') {
					n1 = n2;
				} else if (num == 'c') {
					n1 = n3;
				} else if (num == 'a') {
					continue;
				} else {
					n1 = num - '0';
				}
				break;
			case 'b':
				if (num == 'a') {
					n2 = n1;
				} else if (num == 'c') {
					n2 = n3;
				} else if (num == 'b') {
					continue;
				} else {
					n2 = num - '0';
				}
				break;
			case 'c':
				if (num == 'b') {
					n3 = n2;
				} else if (num == 'a') {
					n3 = n1;
				} else if (num == 'c') {
					continue;
				} else {
					n3 = num - '0';
				}
				break;
		}
	} 
	printf("%d %d %d", n1, n2, n3);
}

void ContinuationRise () {
    int num, count = 1, ans = 0, p, n;
    cin >> num;
    // int arr[n];
    for (int i = 0; i < num; i++){
        if (i == 0) {
            cin >> p;
        }else {
            cin >> n;
            if (n > p) {
                count++;
            } else {
                if (ans < count) {
                    ans = count;
                }
                count = 1;
            }
            p = n;
        }
    }
    if (ans < count) {
        ans = count;
    }
    cout << ans;
}

void NumbCount () {
    int m, n, temp;
    cin >> m >> n;
    int arr[10] = {0};
    for (int i = m; i <= n; i++){
        temp = i;
        while (temp > 0) {
            arr[temp % 10]++;
            temp /= 10;
        }
    }
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
}

void ChessBoard () {
    int h, w, s = 0, r = 0;
    cin >> h >> w;
    for (int i = 1; i <= h; i++) {
        for ( int j = 1; j <= w; j++) {
            if (i == j) {
                s += (h - i + 1) * (w - j + 1);
            }else {
                r += (h - i + 1) * (w - j + 1);
            }
        }
    }
    cout << s << " " << r;
}