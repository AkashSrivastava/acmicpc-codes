如果您在环境变量path中配置了g++，则可直接运行run.bat,否者请编译main.cpp然后放在相应位置运行。

task1:
本程序可解决附件1和附件2。
需要将000.bmp到018.bmp放在input文件夹内，然后运行。
图片将输出在picture.bmp中，对应的表格输出在table.txt中。
本程序采用动态规划算法。

task2-zh:
本程序课解决附件3，最后会形成6个正确的块，需要人工干预最后拼接成完整的块。
需要将000.bmp到208.bmp放在input文件夹内，然后运行。
生成的6个块分别在xxx.bmp中，每个xxx.bmp对应一个tablexxx.txt，txt中为这个图片的表格。
本程序采用针对中文的匹配代价函数+贪心+伏格尔类遗传算法。

task2-en:
本程序课解决附件4，最后会形成9个正确的块，需要人工干预最后拼接成完整的块。
需要将000.bmp到208.bmp以及附件2最后生成的picture.bmp(需要命名为alphabet.bmp)放在input文件夹内，然后运行。
生成的9个块分别在xxx.bmp中，每个xxx.bmp对应一个tablexxx.txt，txt中为这个图片的表格。
本程序采用针对英文的匹配代价函数+贪心+伏格尔类遗传算法。

task3:
本程序课解决附件6，最后会形成6个正确的块(相同的块正反面各算一块)，需要人工干预最后拼接成完整的块。
需要将000a.bmp到208a.bmp以及000b.bmp到208b.bmp以及附件2最后生成的picture.bmp(需要命名为alphabet.bmp)放在input文件夹内，然后运行。
生成的6个块分别在xxx.bmp中，每个xxx.bmp对应一个tablexxx.txt，txt中为这个图片的表格。
本程序采用针对双面英文的匹配代价函数+贪心+伏格尔类遗传算法。

注意：
由于实现论文中的算法时，为了方便编程有很多可以让程序运行得更快的优化没有加入所以task2-en和task3的运行时间会比较久一点。
