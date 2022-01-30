#include <bits/stdc++.h>
using namespace std;

float getJarak(pair<float, float> sudut1, pair<float, float> sudut2) { 
  // Jarak antara dua buah titik adalah akar selisih kuadrat kedua titik pada sumbu x dan y
  // jarak = sqrt((x2-x1)^2 + (y2-y1)^2)
  return sqrt(pow((sudut2.first - sudut1.first),2) + pow((sudut2.second - sudut1.second),2));
}

bool checkRectangle(pair<float, float> sudut1, pair<float, float> sudut2, pair<float, float> sudut3, pair<float, float> sudut4) {
  // Syarat persegi panjang adalah terdapat dua pasang sisi yang sama panjang
  // Pertama cari jarak satu sudut dengan ketiga sudut lainnya
  float jarak12 = getJarak(sudut1, sudut2);
  float jarak13 = getJarak(sudut1, sudut3);
  float jarak14 = getJarak(sudut1, sudut4);

  // Kemudian dicari jarak maximal nya. Sudut pada jarak maksimal tersebut menandakan titik yang berlawanan
  float jarakmax = max(max(jarak12, jarak13), jarak14);

  // Kemudian cari 3 jarak lainnya
  float jarak23 = getJarak(sudut2, sudut3);
  float jarak24 = getJarak(sudut2, sudut4);
  float jarak34 = getJarak(sudut3, sudut4);

  if (jarakmax == jarak12) {
    // Pada conditional and pertama dipastikan bahwa ada dua pasang sisi sama jarak
    // Pada conditional and kedua dipastikan bahwa berbentuk persegi panjang, bukan persegi
    return (jarak13 == jarak24 && jarak14 == jarak23) && (jarak24!=jarak23);
  } else if (jarakmax == jarak13) {
    return (jarak12 == jarak34 && jarak14 == jarak23) && (jarak34 != jarak23);
  } else if (jarakmax == jarak14) {
    return (jarak12 == jarak34 && jarak13 == jarak24) && (jarak34 != jarak24);
  }

  // Apabila ada hasil diluar yang memungkinkan
  return false;
}

int main() {
  // Diketahui persegi panjang memiliki 4 sudut
  // Deklarasikan 4 buah pair, dimana elemen first untuk sb x, elemen second untuk sb y
  pair<float, float> sudut[4];

  cout<<"Masukkan titik 1 sumbu x dan y"<<endl;
  cin >> sudut[0].first >> sudut[0].second;

  cout << "Masukkan titik 2 sumbu x dan y" << endl;
  cin >> sudut[1].first >> sudut[1].second;

  cout << "Masukkan titik 3 sumbu x dan y" << endl;
  cin >> sudut[2].first >> sudut[2].second;

  cout << "Masukkan titik 4 sumbu x dan y" << endl;
  cin >> sudut[3].first >> sudut[3].second;

  bool isrectangle = checkRectangle(sudut[0], sudut[1], sudut[2], sudut[3]);
  if (isrectangle == true) {
    cout << "Titik membentuk persegi panjang" << endl;
  } else {
    cout << "Titik tidak membentuk persegi panjang" << endl;
  }
}