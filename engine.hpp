#include"dekunobou.hpp"
#include"othello.hpp"
//minimaxで末端ノードのときに出力する値
#define win_out 30000//先手側が勝ったときの評価値
#define lose_out -30000//先手側が負けたときの評価値
#define draw_out 0//引き分けのときの評価値

bool turn_p;//エンジン側の手番(応急処置)

/**********paramについて************/
/**********
 0~63: 着手に対する重み
 64: 置ける場所の数に対する重み
 65: 多分確定石(近似値)に対する重み
***********/

//評価関数の読み込みがきついので埋め込む
float param[param_size] = {
    0.884191,
    -0.473784,
    0.421311,
    0.0129131,
    0.0129131,
    0.421311,
    -0.473784,
    0.884191,
    -0.473784,
    -0.728345,
    0.221574,
    0.192712,
    0.192712,
    0.221574,
    -0.728345,
    -0.473784,
    0.421311,
    0.221574,
    0.385439,
    -0.0227518,
    -0.0227518,
    0.385439,
    0.221574,
    0.421311,
    0.0129131,
    0.192712,
    -0.0227518,
    0.165454,
    0.165454,
    -0.0227518,
    0.192712,
    0.0129131,
    0.0129131,
    0.192712,
    -0.0227518,
    0.165454,
    0.165454,
    -0.0227518,
    0.192712,
    0.0129131,
    0.421311,
    0.221574,
    0.385439,
    -0.0227518,
    -0.0227518,
    0.385439,
    0.221574,
    0.421311,
    -0.473784,
    -0.728345,
    0.221574,
    0.192712,
    0.192712,
    0.221574,
    -0.728345,
    -0.473784,
    0.884191,
    -0.473784,
    0.421311,
    0.0129131,
    0.0129131,
    0.421311,
    -0.473784,
    0.884191,
    -0.406054,
    0.0852064
};

//評価値の計算(手番側が有利ならプラス)
float eval_calc(Board board, int move) {
    float out = param[move], moves_opponent_sum = 0;
    //1手すすめる
    board.push(move);
    //相手の合法手をカウント
    LegalMoveList moves(board);
    for (int i = 0; i < moves.size(); ++i)moves_opponent_sum += param[moves[i]];
    out += param[64] * moves_opponent_sum;
    float point_ratio = (float)board.point[!board.turn] / (board.point[!board.turn] + board.point[board.turn]);
    out += param[65] * point_ratio;//すでに置かれている石のうちの自分の石の割合
    return out;
}

//minimax法による先読み
float minimax(Board board, int depth) {
    //候補手の展開
    LegalMoveList moves(board);
    if (moves.size() == 0) {
        //手番を変えて展開
        board.push(-1);
        LegalMoveList moves2(board);
        //終局
        if (moves2.size() == 0) {
            return board.point[turn_p];
        }
        moves = moves2;
    }

    float eval;
    if (board.turn != turn_p)eval = -inf;
    else eval = inf;
    //末端ノードのとき
    if (depth <= 0) {
        for (int i = 0; i < moves.size(); ++i) {
            eval = std::max(eval, eval_calc(board, moves[i]));
        }
        //std::cout<<"depth:"<<depth<<", eval:"<<eval<<std::endl;
        return eval;
    }

    //それ以外のとき
    Board board_ref;
    for (int i = 0; i < moves.size(); ++i) {
        //1手打つ
        board_ref = board;
        board_ref.push(moves[i]);
        if (board.turn == turn_p) {
            eval = std::max(eval, minimax(board_ref, depth - 1));
        }
        else {
            eval = std::min(eval, minimax(board_ref, depth - 1));
        }
    }
    //std::cout<<"depth:"<<depth<<", eval:"<<eval<<std::endl;
    return eval;
}

int go(Board board) {
    float eval = -inf;
    LegalMoveList moves(board);
    //1手だけのときはその手を返す
    if (moves.size() == 1)return moves[0];

    turn_p = board.turn;//エンジン側の手番を取得

    int BestMoves[64];
    int bestmoves_num;
    std::random_device rnd_select;

    bestmoves_num = 0;
    float eval_ref;

    //現在の評価値を算出
    Board board_ref;
    for (int i = 0; i < moves.size(); i++) {
        eval_ref=eval_calc(board,moves[i]);

        //先読みしてみる
        //board_ref = board;
        //board_ref.push(moves[i]);
        //eval_ref = minimax(board_ref, param, 4);
        //std::cout << moves[i] << ": " << eval_ref << std::endl;
        if (eval_ref > eval) {
            bestmoves_num = 0;
            BestMoves[bestmoves_num] = moves[i];
            ++bestmoves_num;
            eval = eval_ref;
        }
        else if (eval_ref == eval) {
            BestMoves[bestmoves_num] = moves[i];
            ++bestmoves_num;
        }
    }
    //for debug
    //std::cout<<"eval: "<<eval<<std::endl;
    return BestMoves[rnd_select() % bestmoves_num];
}