# 百度云链接（更详细，有现成的exe文件
here(https://pan.baidu.com/s/1z4RT5ZN0srXUIVPS0bOUhg)
提取码：yyds
# 作品概述
![image](图片1.png)         ![image](图片3.png)
![image](图片2.png)


## 创意来源和产生背景：
因为语义分割的 AI 应用，因为语义图十分简单，所以我们想通过对语义图进行
加工，生成现实的风景图片，或者艺术图片，这样用户只需简单的操作，就能绘
画出很好的作品
## 作品的用户群体：
本作品可面向所有人
## 主要功能和特色：
用户通过在绘制界面的左侧绘制简单的图画，然后右侧自动生成现实或艺术的风
景图
## 应用价值和前景：
户可以通过简单的绘画，就得到美丽的图片，使热爱绘画的作者更快的体会到绘
画的乐趣，同时也可以使热爱绘画但绘画能力不强的人，体会作为一名“绘画大
师”快乐，本作品从普通人的日常生活出发，为用户更好的体会到绘画的快乐
可以给用户提供一种创造的快乐和成就感，在这个浮躁的时代，用户可也静下心
来绘制自己的“世界”，找到自己的快乐

# 作品的功能和性能需求：
功能是将简单的绘制作品加工，生成现实或艺术的图片
性能需求：windows 系统，cpu 的性能强弱决定加工速度的快慢

# 技术方案
我们先后阅读 pix2pix，pix2pixHD，和 gaugan 等相关的对抗生成网络论文，选
择其中的优点并且结合自身的实际硬件情况（4g GTX1650）自行设计网络
# 总体：
基于对抗生成网络，分别设计产生模型和鉴别模型，然后利用已有的真实图片与
产生模型形成对抗，加速生成器的训练
# 模型介绍：
网络前端后端采用 u-net 的基本结构，中间用 skips 连接
前后两段的中段，选择 resnet 的 residual 模块，减缓梯度消失问题，使网络最
大程度上学习图片中的语义信息
采用对抗的网络结构，为了的到更好的生成器模型，我们又制作了鉴别器，用来
区分生成图片和真实图片，通过两个网络的对抗训练，使生成器模型更好的学习，
优化的更加迅速
对于训练集的图片，我们采用了随机裁剪等图片增强的方法，为了得到鲁棒性较
好的模型，而且可以丰富实验数据
放弃了常规的交叉熵损失函数而采用 lsgan 的最小二乘损失函数，为提高生成图
片的相似性，采用生成图片与目标图片输入到 vgg19 的其中 5 层的 feature map
做损失函数，使网络不仅关注图片的单个像素点，也关注彼此的结构和联系

## 数据训练：
1. 对 256*256 数据 resize 到 286*286，然后随机裁剪
2. 将语义图改成 float32，并且归一化
3. 将语义图传入到生成器，得到生成图片，将生成图片与实际图片传入到预训
练好的 vgg19，选取其中的 5 层 feature maps，做 L1 的损失函数的优化，
4. 将生成图片传入到鉴别器中，真实图片模标输出 30*30 的元素为 1 的矩阵，
生成图片目标输出 30*30 的元素为 0 的矩阵，做损失函数，训练鉴别器
5. 训练 1000epoches，生成器：tf.keras.optimizers.Adam(2e-4, beta_1=0.5)
鉴别器：tf.keras.optimizers.Adam(1.5e-4, beta_1=0.5)
## 改进过程：
因为设备原因，对网络进行了精简。通过消融实验，简化了多余的 residual 个
数，和空间自适应一体化带来的较多参数（可能是因为数据集较少，所以训练效
果不佳）从 1 亿左右的训练参数降到 2 千万个左右



