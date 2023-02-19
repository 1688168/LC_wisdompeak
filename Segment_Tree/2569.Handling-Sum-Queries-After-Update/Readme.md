### 2569.Handling-Sum-Queries-After-Update

本题的本质就是需要高效的区间更新函数来维护nums1，来实现第一类query。对于第二类query，只需要操作`sum += total(nums1)*p`即可，其中total就是对nums1全部元素取和。对于第三类query，就是输出当前的sum。

显然我们会用线段树来实现这样的数据结构。

在现有的模板中，我们肯定会选择带有“区间求和”功能的模板，即`queryRange(a,b)`可以求得nums1里指定区间[a,b]元素的和。但是“区间更新”的功能需要重写：原本的功能是将区间的数值替换为val，这里的区间更新是将里面的元素全部做0/1翻转，这对区间和会产生什么影响呢？假设原本一段区间[a,b]内记录的元素和是info，那么`updateRange(a,b)`造成的影响其实就是`info = (b-a+1)-info`，改动非常简单。

另外，我们还需要对懒标记进行重新的定义。在模板里，`lazy_tag=1`表示该区间的子区间有待更新（即01翻转）。那么`lazy_val`我们需要重新定义为“它的子区间我们还需要翻转多少次”。当我们需要`push_down`的时候，就需要对左右子区间分别进行`lazy_val`次的翻转。