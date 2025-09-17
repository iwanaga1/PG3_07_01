// PG3_07_01.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <string>
#include <chrono>

int main() {
    // 100,000文字の 'a' で初期化された文字列を作成
    std::string a(100000, 'a');

    // コピーにかかる時間を計測
    auto start_copy = std::chrono::high_resolution_clock::now();
    std::string b = a;
    auto end_copy = std::chrono::high_resolution_clock::now();
    auto copy_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_copy - start_copy).count();

    // ムーブにかかる時間を計測
    auto start_move = std::chrono::high_resolution_clock::now();
    std::string c = std::move(a);  // ムーブ
    auto end_move = std::chrono::high_resolution_clock::now();
    auto move_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_move - start_move).count();

    // 結果を表示
    std::cout << "100,000文字を移動とコピーで比較" << std::endl;
    std::cout << "コピー: " << copy_duration << " μs" << std::endl;
    std::cout << "移動  : " << move_duration << " μs" << std::endl;

    // 終了待機
    std::cout << "続行するには何かキーを押してください…";
    std::cin.get();

    return 0;
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
