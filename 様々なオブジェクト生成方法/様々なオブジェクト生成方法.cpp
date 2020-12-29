//実行環境
//Microsoft Visual Studio Community 2019
//Version 16.8.3
//Windows10 Home 1903

// 20201229_色々なオブジェクト生成.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <stdlib.h>

class Sample
{
    int value;
public:
    Sample(int value) : value(value)
    {
        printf("コンストラクタ呼び出し　value = %d\n", this->value);
    }
    Sample(const Sample& s) : value(s.value)
    {
        printf("コピーコンストラクタ呼び出し　value = %d\n", this->value);
    }
    ~Sample()
    {
        printf("デストラクタ呼び出し　value = %d\n", this->value);
    }
};

int main()
{
    printf("main処理開始\n");
    Sample(000);                       //一時オブジェクト
    Sample s1 = Sample(111);           //静的オブジェクト
    {
        Sample s2 = 222;               //一時オブジェクト
    }
    Sample* s3 = new Sample(333);      //動的オブジェクト


    //参照: https://www.youtube.com/watch?v=F2O7ZXIY31s 9:40
    //一時オブジェクトの lifetime を伸ばしたから、静的オブジェクトになると考えた。
    {
        const Sample& s4 = 444;        //静的オブジェクト エラー:注括弧を抜けるとデストラクトしてしまう。
    }
    {
        Sample&& s5 = 555;             //静的オブジェクト エラー:注括弧を抜けるとデストラクトしてしまう。
    }

    {
        void* mem = malloc(sizeof Sample);                          
        Sample* s6 = new(mem) Sample(666);                          //動的オブジェクト
    }
    Sample* s7 = new Sample[2]{ 777,778 };                          //動的オブジェクト
    Sample s8 = s1;                                                 //静的オブジェクト
    printf("main処理終了\n");
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
