### 3169.Count-Days-Without-Meetings

很明显这是一道扫描线的题目。对于每个区间[s,e]的会议，我们记录`Map[s]++`和`Map[e+1]--`. 最后我们将Map里的所有key按照时间顺序走一遍，累加差分值至count。

当count从正数降为零时，说明没有任何会议，此时记录当前日期cur。当count从零变成正数时，说明出现了会议，那么就将当前日期减去cur，即为最近一段没有会议的时长。

最终统计所有无会议的时长之和。
