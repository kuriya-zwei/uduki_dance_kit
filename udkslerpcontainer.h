#ifndef UDKSLERPCONTAINER_H
#define UDKSLERPCONTAINER_H


template<class Data>
class udkSlerpContainer
{
public:


    /**
     * @brief 補間関数をセットする ただし，NullPointerの時は何もしない
     */
    void slerp_func(const sp<ISlerpFunction> slerpfunc);


    /**
     * @brief 現在のフレームから補間した値を求める
     */
    void getValue(const Data *result, const int current_frame) const;

private:
    sp<ISlerpFunction> _slerp_func;
    std::vector< std::pair<int,Data> > _key_frames;

    /**
     * @brief 指定したフレームの左にあるキーフレームを求める
     * @return 指定したフレームの左にあるキーフレームを返す，結果を入れるポインタが0の時は何もしない，
     *          最大キーフレームを超えるフレームが入力されたときは最大キーフレームを，左にあるキーフレームがないときは-1を返す
     */
    void getLeftKeyFrame(const int *near_frame_idx, const int current_frame) const;
};


/**
 * @brief 補間関数をセットする ただし，NullPointerの時は何もしない
 */
template<class Data>
void udkSlerpContainer<Data>:: setSlerpFunc(const sp<ISlerpFunction> slerp_func)
{
    if (slerp_func.get() != 0)
        _slerp_func = slerp_func;
}


/**
 * @brief 現在のフレームから補間した値を求める
 */
template<class Data>
void udkSlerpContainer<Data>::getValue(const Data* result,const int current_frame) const
{
    //結果を入れるポインタが0だったら何もしない
    if (near_frame ==0)
    {
        return;
    }

    //補完用関数ポインタが0だったら何もしない
    if (_slerp_func.get() ==0)
    {
        return;
    }

    //左にあるキーフレームを求める
    int near_frame_idx = 0;
    getNearFrame(&near_frame_idx, current_frame);

    //現在のフレームの左と右のキーフレームを求める
    int left_frame = 0, right_frame = 0;
    left_frame = _key_frames[near_frame_idx];
    right_frame = _key_frames[near_frame_idx+1];

    //補完を行う
    _slerp_func.slerp(result, left_frame, current_frame, right_frame, _key_frames);

}


/**
 * @brief 指定したフレームの左にあるキーフレームを求める
 * @return 指定したフレームの左にあるキーフレームを返す，結果を入れるポインタが0の時は何もしない，
 *          最大キーフレームを超えるフレームが入力されたときは最大キーフレームを，左にあるキーフレームがないときは-1を返す
 */
template<class Data>
void udkSlerpContainer<Data>::getLeftKeyFrame(const int *near_frame_idx, const int current_frame) const
{
    //結果を入れるポインタが0だったら何もしない
    if (near_frame_idx ==0)
    {
        return;
    }

    //二分探索
    int length = (int)_key_frames.size();

    int left = 0;
    int right = length;

    //結果
    int result = -1;

    while (left < right) {
        int mid = (left + right) /2;

        //値(フレーム)が最大値を超えている場合
        if ( current_frame >= _key_frames[length-1])
        {
            result = length - 1;
            break;
        }


        if ((mid + 1) >= length)
        {
            //インデックスが最大値を超えている場合
            result = -1;
            break;
        }
        else if ( (_key_frames[mid] <= current_frame) && (current_frame < _key_frames[mid+1]) )
        {
            //引数で渡されたフレームが二つの要素の間にある⇒それが欲しい近傍フレーム
            result = mid;
            break;
        }
        else if (current_frame < _key_frames[mid])
        {
            //現在のフレームがチェック中の中央の値より小さい⇒大きい方の値を狭める
            right = mid;
        }
        else
        {
            //現在のフレームがチェック中の中央の値より大きい⇒小さい方の値を狭める
            left = mid + 1;
        }
    }

    //結果を代入して終わり(適切なフレームが見つからなかったときは-1を代入)
    *near_frame_idx = result;
}


#endif // UDKSLERPCONTAINER_H
