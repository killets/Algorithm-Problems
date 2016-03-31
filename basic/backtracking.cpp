见22题，
backtracking有个基本的框架模式

主函数
（调用helper）

helper(){
if() //中断，或完成条件
{
存结果；
print等
}

for each{
do
helper(new);
undo
}

}


//update:
131题，除了backtracking，想不到其它更好的方法
