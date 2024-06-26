### 3161.Block-Placement-Queries

本题的第一类query会在数轴上不断插入block，通常情况下每插入一个block，就会隔出两个区间。当遇到第二类query时，我们只需要在[0,x]范围内查看这些区间，找出最大的区间长度，再与sz比较即可。此时我们只需要把每个区间的长度，作为该区间右端点的一个属性，就可以发现就是在[0,x]里求最大值。所以我们容易想到，只需要构造一棵线段树，其中queryRange是求任意一段区间内的最大值。初始状态每个点的值是0.

更具体的，对于第一类操作，我们在x处插入一个block时，找到它之前已经存在的block位置记做a，之后已经存在的block位置记做b，那么我们只需要对线段树进行单点更新：在x处更新属性x-a，在b处更新数值b-x（前提是b存在）。

对于第二类操作，我们只需要在线段树的[0,x]范围里找最大值。特别注意，如果x处本身并没有block，我们还需要考察x之前的那个block（记做a）到x这段空间长度。

最后，对于一个x，如果找到它之前和之后的block呢？只需要维护一个有序容器set即可，不断将x插入其中，并且用lower_bound和upper_bound找到其在Set里的前后元素。
