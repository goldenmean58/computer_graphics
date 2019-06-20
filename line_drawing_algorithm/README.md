# 直线扫描转换算法(Line Drawing Algorithm)
将直线离散化(转化为点的集合)，要求与直线足够接近，线条亮度均匀（要求离散点分布均匀），效率高，常用的算法有`DDA`与`Bresenham`算法
## DDA(Digital Differential Analyzer)
即数值差分算法
1. 设直线起始点为`(x0,y0)`，终点为`(x1,y1)`
2. 显然可以算出`dx=x1-x0`,`dy=y1-y0`即差分
3. 接下来选择步长，根据第2步算出的`dx`与`dy`，要想接近原直线我们就要保证变化够小即更多点??，可以直接选取`dx`or`dy`作为步长，如果`|dx|>|dy|`则需要在x上更多的步长，即`step=|dx|>|dy|?|dx|:|dy|`
4. 计算`x`,`y`的每一次变化量:`Xincrement=dx/step; Yincrement=dy/step`
5. 根据第四步的增量循环step次叠加`(Xk+1=Xk+Xincrement; Yk+1=Yk+Yincrement)`出所有点的坐标
