#include <iostream>
#include <string>
#include <map>

using namespace std;

string decode(const string& origin);

long main() {
    long n;
    cin >> n;
    map<string, long> phones;
    string origin;
    map<string, long>::iterator iter;
    for (long i=0; i<n; i++) {
        cin >> origin;
        string decoded = decode(origin);
        iter = phones.find(decoded);
        if (iter == phones.end()) {
            phones.insert(pair<string, long>(decoded, 1));
        } else {
            iter->second++;
        }
    }

    bool flag = true;
    for (iter = phones.begin(); iter != phones.end(); iter++) {
        if (iter->second <= 1)
            continue;
        cout << iter->first.substr(0, 3) << '-' << iter->first.substr(3, 8)
             << ' ' << iter->second << endl;
        flag = false;
    }
    if (flag)
        cout << "No duplicates." << endl;
    return 0;
}

string decode(const string& origin) {
    string decoded;
    for (long i = 0; i < origin.length(); i++) {
        switch (origin[i]) {
            case 'A': case 'B': case 'C': case '2':
                decoded += '2';
                break;
            case 'D': case 'E': case 'F': case '3':
                decoded += '3';
                break;
            case 'G': case 'H': case 'I': case '4':
                decoded += '4';
                break;
            case 'J': case 'K': case 'L': case '5':
                decoded += '5';
                break;
            case 'M': case 'N': case 'O': case '6':
                decoded += '6';
                break;
            case 'P': case 'R': case 'S': case '7':
                decoded += '7';
                break;
            case 'T': case 'U': case 'V': case '8':
                decoded += '8';
                break;
            case 'W': case 'X': case 'Y': case '9':
                decoded += '9';
                break;
            case '1': case '0':
                decoded += origin[i];
                break;
        }
    }
    return decoded;
}