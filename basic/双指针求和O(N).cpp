由3sum想到的：

front, back指向首尾，相向移动
当sum<target时，右移动front，>时，左移动back
复杂度o(n)

naive的做法是双层for
复杂度o(n^2)

//---------------------------------------------------------
75题， sort colors,分三堆的问题，将0和2朝两边摆放
