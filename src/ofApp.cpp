#include "ofApp.h"

ofSoundPlayer scream;
ofSoundPlayer bark;
ofSoundPlayer bress;
ofSoundPlayer backmusic;
ofSoundPlayer bark2;
ofSoundPlayer sadness;
ofSoundPlayer bark3;
ofSoundPlayer bark4;

//変数(鼻の中心座標)
float x, y, x2, y2, x3[3], y3[3], x4[2], y4[2], x5[5], y5[5];
//変数(基準となる大きさ=鼻の高さ)
int dogsize = 20;

float dx, dy, dy2, dx3[3], dy3[3], dx4[2];
int toumei[5];
int r, g, b;

//--------------------------------------------------------------
void ofApp::setup(){

	//レギュレーション
	ofBackground(240, 134, 55);
	ofSetCircleResolution(64);
	ofSetLineWidth(dogsize / 10);
	//犬のカラーリング初期値
	r = 232;
	g = 189;
	b = 134;

	//犬、初期位置
	x = ofGetWidth() / 2;
	y = 500;


	x2 = ofGetWidth() - dogsize * 8;
	y2 = ofGetHeight() - dogsize * 1.5;

	for (int i = 0; i < 3; i++)
	{
		x3[i] = dogsize * 4.5;
		y3[i] = ofGetHeight() - dogsize * 2.5;
	}

	for (int i = 0; i < 2; i++)
	{
		x4[i] = dogsize;
		y4[i] = ofGetHeight() - dogsize;
	}

	x5[0] = ofGetWidth() / 2 - dogsize * 18.5;
	x5[1] = ofGetWidth() / 2 - dogsize * 8.5;
	x5[2] = ofGetWidth() / 2 - dogsize * 13.5;
	x5[3] = ofGetWidth() / 2 - dogsize * 13.5;
	x5[4] = ofGetWidth() / 2 - dogsize * 13.5;
	for (int i = 0; i < 2; i++)
	{
		y5[i] = ofGetHeight() - dogsize * 8;
	}
	y5[2] = ofGetHeight() - dogsize * 3;
	y5[3] = ofGetHeight() - dogsize * 13;
	y5[4] = ofGetHeight() - dogsize * 8;


	//音楽
	scream.load("dogscream.mp3");
	scream.setLoop(false);

	bark.load("dogbark.mp3");
	bark.setLoop(false);

	bress.load("dogbress.mp3");
	bress.setLoop(true);

	backmusic.load("kaeru.mp3");
	backmusic.setLoop(true);
	backmusic.play();

	bark2.load("dogbark2.mp3");
	bark2.setLoop(false);

	sadness.load("sadness.mp3");
	sadness.setLoop(false);

	bark3.load("dogbarking1.mp3");
	bark3.setLoop(false);

	bark4.load("dog1b.mp3");
	bark4.setLoop(false);

}

//--------------------------------------------------------------
void ofApp::update(){

	//犬のアニメーション、画面端まで行ったら折り返すプログラム
	if (x > ofGetWidth() - dogsize * 5.6)
	{
		dx = -dx;

	}
	if (x < dogsize*5.6)
	{
		dx = -dx;

	}
	x = x + dx;

	if (y < dogsize*8.3)
	{
		dy = -dy;
	}
	if (y > ofGetHeight() - dogsize * 3.2)
	{
		dy = -dy;
	}
	y = y + dy;


	//ボール遊び。犬の頭の上で周期的に動くようプログラム
	if (y2 > y - dogsize * 15)
	{
		dy2 = -dy2;
	}
	if (y2 <= y - dogsize * 7.5)
	{
		dy2 = -dy2;
	}
	y2 = y2 + dy2;


	//カラーボール。画面端で折り返すプログラム
	for (int i = 0; i < 3; i++)
	{
		if (x3[i] <= dogsize * 2.5)
		{
			dx3[i] = -dx3[i];
		}
		if (x3[i] >= ofGetWidth() - dogsize * 2.5)
		{
			dx3[i] = -dx3[i];
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (y3[i] <= dogsize * 2.5)
		{
			dy3[i] = -dy3[i];
		}
		if (y3[i] >= ofGetHeight() - dogsize * 2.5)
		{
			dy3[i] = -dy3[i];
		}
	}
	x3[0] = x3[0] + dx3[0];
	x3[1] = x3[1] + dx3[1];
	x3[2] = x3[2] + dx3[2];
	y3[0] = y3[0] + dy3[0];
	y3[1] = y3[1] + dy3[1];
	y3[2] = y3[2] + dy3[2];

	//悪(紫)ボール
	for (int i = 0; i < 2; i++)
	{
		if (x4[i] <= dogsize)
		{
			dx4[i] = -dx4[i];
		}
		if (x4[i] >= ofGetWidth() - dogsize)
		{
			dx4[i] = -dx4[i];
		}
	}
	x4[0] = x4[0] + dx4[0];
	x4[1] = x4[1] + dx4[1];

}

//--------------------------------------------------------------
void ofApp::draw(){

	//以下、犬の描画
	//耳
	ofFill();
	ofSetColor(r, g, b);
	ofDrawTriangle(x - (dogsize*3.2), y - (dogsize*8.3), x - dogsize, y - (dogsize*6.1), x - (dogsize * 5), y - (dogsize*1.3));
	ofDrawTriangle(x + (dogsize*3.2), y - (dogsize*8.3), x + dogsize, y - (dogsize*6.1), x + (dogsize * 5), y - (dogsize*1.3));
	//耳の穴
	ofSetColor(255, 250, 240);
	ofDrawTriangle(x - (dogsize*3.12), y - (dogsize*7.9), x - (dogsize*1.1), y - (dogsize*5.9), x - (dogsize*3.9), y - (dogsize*4.1));
	ofDrawTriangle(x + (dogsize*3.12), y - (dogsize*7.9), x + (dogsize*1.1), y - (dogsize*5.9), x + (dogsize*3.9), y - (dogsize*4.1));
	//首輪
	ofSetColor(0, 161, 90, toumei[0]);
	ofDrawEllipse(x, y + dogsize * 3, 100, 30);
	ofDrawLine(x, y + dogsize * 3, mouseX, mouseY);
	//顔の土台
	ofFill();
	ofSetColor(r, g, b);
	ofDrawCircle(x, y - (dogsize*1.6), dogsize*4.6);
	ofDrawEllipse(x, y + (dogsize / 2), dogsize*10.6, dogsize*5.4);
	ofDrawTriangle(x - (dogsize*5.3), y + (dogsize*0.4), x - (dogsize * 5), y - (dogsize*1.3), x, y - (dogsize*0.9));
	ofDrawTriangle(x + (dogsize*5.3), y + (dogsize*0.4), x + (dogsize * 5), y - (dogsize*1.3), x, y - (dogsize*0.9));
	ofDrawTriangle(x - (dogsize * 5), y - (dogsize*1.3), x - (dogsize*4.5), y - (dogsize*0.3), x - (dogsize*4.5), y - (dogsize*2.5));
	ofDrawTriangle(x + (dogsize * 5), y - (dogsize*1.3), x + (dogsize*4.5), y - (dogsize*0.3), x + (dogsize*4.5), y - (dogsize*2.5));
	//顔周りの毛(左側、上の毛から描画)
	ofDrawTriangle(x - (dogsize*5.6), y + (dogsize*0.9), x - (dogsize * 5), y + (dogsize*1.1), x - (dogsize*5.2), y + (dogsize / 10));
	ofDrawEllipse(x - (dogsize*5.2), y + (dogsize*0.9), dogsize / 5 * 4, dogsize / 5);
	ofDrawTriangle(x - (dogsize*5.4), y + (dogsize*1.9), x - (dogsize * 5), y - (dogsize / 10), x - (dogsize*4.8), y + (dogsize*1.9));
	ofDrawEllipse(x - (dogsize*4.5), y + (dogsize*1.8), dogsize / 5 * 8, (dogsize - 5) / 3);
	ofDrawEllipse(x - (dogsize*4.34), y + (dogsize*1.24), dogsize / 5 * 6, dogsize / 5 * 7);
	ofDrawTriangle(x - (dogsize*4.9), y + (dogsize*2.4), x - (dogsize*4.6), y + (dogsize*1.7), x - (dogsize * 2), y + (dogsize*2.8));
	ofDrawEllipse(x - (dogsize*3.88), y + (dogsize*2.4), dogsize * 2, dogsize / 5 * 2);
	ofDrawEllipse(x - (dogsize*3.04), y + (dogsize*2.46), dogsize * 2, dogsize / 5 * 2);
	ofDrawEllipse(x - (dogsize*2.2), y + (dogsize*2.52), dogsize * 2, dogsize / 5 * 2);
	ofDrawEllipse(x - (dogsize*1.36), y + (dogsize*2.58), dogsize * 2, dogsize / 5 * 2);
	ofDrawLine(x - (dogsize*3.88), y + (dogsize*2.48), x - (dogsize*1.36), y + (dogsize*2.82));
	//顔周りの毛(右側、上の毛から描画)
	ofDrawTriangle(x + (dogsize*5.6), y + (dogsize*0.9), x + (dogsize*4.7), y + (dogsize*1.1), x + (dogsize*5.2), y + (dogsize / 10));
	ofDrawEllipse(x + (dogsize*5.24), y + (dogsize*0.9), dogsize / 5 * 4, dogsize / 5);
	ofDrawTriangle(x + (dogsize*5.3), y + (dogsize*1.9), x + (dogsize * 5), y + (dogsize / 50), x - (dogsize*4.8), y + (dogsize*1.5));
	ofDrawEllipse(x + (dogsize*4.5), y + (dogsize*1.86), dogsize / 5 * 8, (dogsize - 5) / 3);
	ofDrawEllipse(x + (dogsize*4.3), y + (dogsize*1.3), dogsize / 5 * 6, dogsize / 5 * 7);
	ofDrawTriangle(x + (dogsize*4.9), y + (dogsize*2.5), x + (dogsize*4.6), y + (dogsize*1.7), x + (dogsize * 2), y + (dogsize*2.8));
	ofDrawEllipse(x + (dogsize*3.88), y + (dogsize*2.5), dogsize * 2, dogsize / 5 * 2);
	ofDrawEllipse(x + (dogsize*3.04), y + (dogsize*2.56), dogsize * 2, dogsize / 5 * 2);
	ofDrawEllipse(x + (dogsize*2.2), y + (dogsize*2.62), dogsize * 2, dogsize / 5 * 2);
	ofDrawEllipse(x + (dogsize*1.36), y + (dogsize*2.68), dogsize * 2, dogsize / 5 * 2);
	ofDrawLine(x + (dogsize*3.98), y + (dogsize*2.58), x + (dogsize*1.46), y + (dogsize*2.82));
	//鼻筋とその周り
	ofSetColor(255, 250, 240);
	ofDrawRectangle(x - (dogsize*0.8), y - (dogsize*4.5), dogsize / 5 * 8, dogsize * 6);
	ofDrawRectangle(x - (dogsize * 2), y - dogsize, dogsize * 4, dogsize * 2);
	ofSetColor(r, g, b);
	ofDrawEllipse(x - (dogsize*0.82), y - (dogsize * 3), dogsize / 5 * 3, dogsize * 4);
	ofDrawEllipse(x + (dogsize*0.82), y - (dogsize * 3), dogsize / 5 * 3, dogsize * 4);
	//口周り
	ofSetColor(255, 250, 240);
	ofDrawEllipse(x, y + (dogsize*1.5), dogsize * 8, dogsize * 3);
	ofSetColor(r, g, b);
	ofDrawEllipse(x - (dogsize*2.7), y - (dogsize*0.3), dogsize * 3, dogsize * 2);
	ofDrawEllipse(x + (dogsize*2.7), y - (dogsize*0.3), dogsize * 3, dogsize * 2);
	ofDrawEllipse(x - (dogsize*2.16), y - (dogsize*1.54), dogsize * 3, dogsize * 4);
	ofDrawEllipse(x + (dogsize*2.16), y - (dogsize*1.54), dogsize * 3, dogsize * 4);
	//顔上部の白い模様
	ofSetColor(255, 250, 240);
	ofDrawEllipse(x, y - (dogsize*4.98), dogsize * 5, dogsize*2.2);
	ofSetColor(r, g, b);
	ofDrawCircle(x - (dogsize*1.96), y - (dogsize * 4), dogsize / 5 * 7);
	ofDrawCircle(x + (dogsize*1.96), y - (dogsize * 4), dogsize / 5 * 7);
	//頬
	ofSetColor(250, 128, 114, 90);
	ofDrawCircle(x - (dogsize*4.1), y - (dogsize / 10), dogsize / 5 * 4);
	ofDrawCircle(x + (dogsize*4.1), y - (dogsize / 10), dogsize / 5 * 4);
	//口(マウスが付近にある場合とない場合で条件分岐)
	if ((mouseX - (x + dogsize * 2.2) <= dogsize / 5 * 3 && mouseX - (x + dogsize * 2.2) >= -(dogsize / 5 * 3) && mouseY - (y - dogsize * 0.6) <= dogsize / 5 * 3 && mouseY - (y - dogsize * 0.6) >= -(dogsize / 5 * 3)) ||
		((mouseX - (x - dogsize * 2.2) <= dogsize / 5 * 3 && mouseX - (x - dogsize * 2.2) >= -(dogsize / 5 * 3) && mouseY - (y - dogsize * 0.6) <= dogsize / 5 * 3 && mouseY - (y - dogsize * 0.6) >= -(dogsize / 5 * 3))))
	{
		ofSetColor(66, 44, 7);
		ofDrawEllipse(x - (dogsize*0.8), y + (dogsize*1.5), dogsize / 5 * 8, dogsize / 5 * 6);
		ofDrawEllipse(x + (dogsize*0.8), y + (dogsize*1.5), dogsize / 5 * 8, dogsize / 5 * 6);
		ofSetColor(255, 250, 240);
		ofDrawEllipse(x - (dogsize*0.8), y + (dogsize*1.6), dogsize / 5 * 8, dogsize / 5 * 6);
		ofDrawEllipse(x + (dogsize*0.8), y + (dogsize*1.6), dogsize / 5 * 8, dogsize / 5 * 6);
		ofSetColor(255, 250, 240);
		ofDrawRectangle(x - (dogsize*0.6), y + (dogsize*0.3), dogsize / 5 * 6, dogsize / 5 * 3);
	}
	else
	{
		ofSetColor(245, 178, 172);
		ofDrawEllipse(x, y + (dogsize*1.3), dogsize / 5 * 8, dogsize * 2);
		ofSetColor(66, 44, 7);
		ofNoFill();
		ofDrawEllipse(x, y + (dogsize*1.3), dogsize / 5 * 8, dogsize * 2);
		ofSetColor(66, 44, 7);
		ofFill();
		ofDrawEllipse(x - (dogsize*0.8), y + (dogsize*0.9), dogsize / 5 * 8, dogsize / 5 * 6);
		ofDrawEllipse(x + (dogsize*0.8), y + (dogsize*0.9), dogsize / 5 * 8, dogsize / 5 * 6);
		ofSetColor(255, 250, 240);
		ofDrawEllipse(x - (dogsize*0.8), y + (dogsize*0.8), dogsize / 5 * 8, dogsize / 5 * 6);
		ofDrawEllipse(x + (dogsize*0.8), y + (dogsize*0.8), dogsize / 5 * 8, dogsize / 5 * 6);
		ofSetColor(255, 250, 240);
		ofDrawRectangle(x - (dogsize*0.6), y + (dogsize*0.3), dogsize / 5 * 6, dogsize / 5 * 3);
	}
	//鼻
	ofSetColor(66, 44, 7);
	ofDrawEllipse(x, y, dogsize / 5 * 8, dogsize);
	//右目(マウスが付近にある場合とない場合で条件分岐)
	if ((mouseX - (x + dogsize * 2.2) <= dogsize / 5 * 3 && mouseX - (x + dogsize * 2.2) >= -(dogsize / 5 * 3) && mouseY - (y - dogsize * 0.6) <= dogsize / 5 * 3 && mouseY - (y - dogsize * 0.6) >= -(dogsize / 5 * 3)) ||
		((mouseX - (x - dogsize * 2.2) <= dogsize / 5 * 3 && mouseX - (x - dogsize * 2.2) >= -(dogsize / 5 * 3) && mouseY - (y - dogsize * 0.6) <= dogsize / 5 * 3 && mouseY - (y - dogsize * 0.6) >= -(dogsize / 5 * 3))))
	{
		ofSetColor(66, 44, 7);
		ofDrawLine(x + (dogsize*1.7), y - (dogsize*1.1), x + (dogsize*2.7), y + (dogsize*0.1));
		ofDrawLine(x + (dogsize*1.7), y + (dogsize*0.1), x + (dogsize*2.7), y - (dogsize*1.1));
	}
	else
	{
		ofSetColor(66, 44, 7);
		ofDrawCircle(x + (dogsize*2.2), y - (dogsize*0.6), dogsize / 5 * 3);
	}
	//左目(マウスが付近にある場合とない場合で条件分岐)
	if ((mouseX - (x + dogsize * 2.2) <= dogsize / 5 * 3 && mouseX - (x + dogsize * 2.2) >= -(dogsize / 5 * 3) && mouseY - (y - dogsize * 0.6) <= dogsize / 5 * 3 && mouseY - (y - dogsize * 0.6) >= -(dogsize / 5 * 3)) ||
		((mouseX - (x - dogsize * 2.2) <= dogsize / 5 * 3 && mouseX - (x - dogsize * 2.2) >= -(dogsize / 5 * 3) && mouseY - (y - dogsize * 0.6) <= dogsize / 5 * 3 && mouseY - (y - dogsize * 0.6) >= -(dogsize / 5 * 3))))
	{
		ofDrawLine(x - (dogsize*1.7), y - (dogsize*1.1), x - (dogsize*2.7), y + (dogsize*0.1));
		ofDrawLine(x - (dogsize*1.7), y + (dogsize*0.1), x - (dogsize*2.7), y - (dogsize*1.1));
	}
	else
	{
		ofSetColor(66, 44, 7);
		ofDrawCircle(x - (dogsize*2.2), y - (dogsize*0.6), dogsize / 5 * 3);
	}
	//ハイライト(目のハイライト、マウスが付近にある場合とない場合で条件分岐)
	ofSetColor(255, 250, 250);
	ofDrawCircle(x + (dogsize*0.4), y - (dogsize*0.2), dogsize / 6.25);
	if ((mouseX - (x + dogsize * 2.2) <= dogsize / 5 * 3 && mouseX - (x + dogsize * 2.2) >= -(dogsize / 5 * 3) && mouseY - (y - dogsize * 0.6) <= dogsize / 5 * 3 && mouseY - (y - dogsize * 0.6) >= -(dogsize / 5 * 3)) ||
		((mouseX - (x - dogsize * 2.2) <= dogsize / 5 * 3 && mouseX - (x - dogsize * 2.2) >= -(dogsize / 5 * 3) && mouseY - (y - dogsize * 0.6) <= dogsize / 5 * 3 && mouseY - (y - dogsize * 0.6) >= -(dogsize / 5 * 3))))
	{

	}
	else
	{
		ofDrawCircle(x + (dogsize*2.2), y - ((dogsize / 5) * 4), dogsize / 5);
		ofDrawCircle(x - (dogsize * 2.2), y - (dogsize*0.8), dogsize / 5);
	}

	//ヘディングボール
	ofSetColor(238, 201, 0);
	ofDrawCircle(x2, y2, dogsize*1.5);
	ofSetColor(255, 250, 250);
	ofDrawCircle(x2 + dogsize * 0.8, y2 - dogsize / 3, dogsize / 4);

	//カラーボール(青ボール)
	for (int i = 0; i < 3; i++)
	{
		ofSetColor(0, 112, 155);
		ofDrawCircle(x3[i], y3[i], dogsize*2.5);
		ofSetColor(255, 250, 250);
		ofDrawCircle(x3[i] + dogsize * 1.4, y3[i] - dogsize / 2, dogsize / 4);
	}
	//顔の汚れ(カラーボールが付着した場合の犬の顔の汚れの描画)
	ofSetColor(0, 112, 155, toumei[1]);
	ofDrawEllipse(x + dogsize * 4, y - dogsize * 2, 20, 30);

	ofSetColor(0, 112, 155, toumei[2]);
	ofDrawEllipse(x - dogsize * 3, y + dogsize * 1.5, 50, 30);
	ofDrawEllipse(x - dogsize * 3.5, y + dogsize * 2, 40, 20);

	ofSetColor(0, 112, 155, toumei[3]);
	ofDrawEllipse(x - dogsize * 2.2, y - dogsize * 4, 60, 30);
	ofDrawEllipse(x - dogsize * 1.5, y - dogsize * 4.7, 40, 20);

	//悪(紫)ボール
	for (int i = 0; i < 2; i++)
	{
		ofSetColor(112, 63, 150);
		ofDrawCircle(x4[i], y4[i], dogsize);
	}

	//コントローラー
	ofSetColor(173, 46, 108, toumei[4]);
	ofDrawTriangle(x5[0] - dogsize * 1.5, y5[0], x5[0] + dogsize * 1.5, y5[0] + dogsize * 3, x5[0] + dogsize * 1.5, y5[0] - dogsize * 3);
	ofDrawTriangle(x5[1] + dogsize * 1.5, y5[1], x5[1] - dogsize * 1.5, y5[1] + dogsize * 3, x5[1] - dogsize * 1.5, y5[1] - dogsize * 3);
	ofDrawTriangle(x5[2], y5[2] + dogsize * 1.5, x5[2] - dogsize * 3, y5[2] - dogsize * 1.5, x5[2] + dogsize * 3, y5[2] - dogsize * 1.5);
	ofDrawTriangle(x5[3], y5[3] - dogsize * 1.5, x5[3] - dogsize * 3, y5[3] + dogsize * 1.5, x5[3] + dogsize * 3, y5[3] + dogsize * 1.5);
	ofDrawCircle(x5[4], y5[4], dogsize * 3);

	//紫ボールに触れたときの顔の色の変化
	for (int i = 0; i < 2; i++)
	{
		if (x - x4[i] <= dogsize * 4.5 && x - x4[i] >= -(dogsize*4.5) && y + (dogsize*1.5) - y4[i] <= dogsize * 4 && y - (dogsize*1.5) - y4[i] >= -(dogsize * 4))
		{
			r = 112;
			g = 63;
			b = 150;
			sadness.play();
		}
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int mx, int my, int button){

	//散歩
	x = mx + 100;
	y = my - 100;
	toumei[0] = 255;

	//カラーボールモード・ペナルティ(犬の顔の汚れは最初透明度が0になっているが、カラーボールが付着した際に、透明度を255まであげ可視化)
	//インタラクティブ要素のため、犬を自分で動かしているとき(マウスドラッグの際)のみ、ペナルティが発生するようにプログラム
	if (x - x3[0] <= dogsize * 4 && x - x3[0] >= -(dogsize * 4) && y - (dogsize*1.5) - y3[0] <= dogsize * 3 && y - (dogsize*1.5) - y3[0] >= -(dogsize * 3))
	{
		toumei[1] = 255;
	}
	if (x - x3[1] <= dogsize * 4 && x - x3[1] >= -(dogsize * 4) && y - (dogsize*1.5) - y3[1] <= dogsize * 3 && y - (dogsize*1.5) - y3[1] >= -(dogsize * 3))
	{
		toumei[2] = 255;
	}
	if (x - x3[2] <= dogsize * 4 && x - x3[2] >= -(dogsize * 4) && y - (dogsize*1.5) - y3[2] <= dogsize * 3 && y - (dogsize*1.5) - y3[2] >= -(dogsize * 3))
	{
		toumei[3] = 255;
	}

}

//--------------------------------------------------------------
void ofApp::mousePressed(int mx, int my, int button){

	//鬼ごっこ(所定位置をクリックした際にゲームが始まる)
	if ((mx - (x - dogsize * 3) <= dogsize * 2 && mx - (x - dogsize * 3) >= -(dogsize * 2) && my - (y - dogsize * 5) <= dogsize * 3.5 && my - (y - dogsize * 5) >= -(dogsize *3.5)))
	{
		bark.play();
		bress.play();
		x = 500;
		y = 500;
		dx = ofRandom(-7, 7);
		dy = ofRandom(-7, 7);
	}
	else if (((mx - (x + dogsize * 3) <= dogsize * 2 && mx - (x + dogsize * 3) >= -(dogsize * 2) && my - (y - dogsize * 5) <= dogsize * 3.5 && my - (y - dogsize * 5) >= -(dogsize *3.5))))
	{
		bark.play();
		bress.stop();
		x = ofGetWidth() / 2;
		y = 500;
		dx = 0;
		dy = 0;
	}
	//鬼ごっこ(難易度高)。目をクリックした際、犬の速度が従来の速度より速くなるようプログラム
	else if ((mx - (x + dogsize * 2.2) <= dogsize / 5 * 3 && mx - (x + dogsize * 2.2) >= -(dogsize / 5 * 3) && my - (y - dogsize * 0.6) <= dogsize / 5 * 3 && my - (y - dogsize * 0.6) >= -(dogsize / 5 * 3)) ||
		((mx - (x - dogsize * 2.2) <= dogsize / 5 * 3 && mx - (x - dogsize * 2.2) >= -(dogsize / 5 * 3) && my - (y - dogsize * 0.6) <= dogsize / 5 * 3 && my - (y - dogsize * 0.6) >= -(dogsize / 5 * 3))))
	{

		scream.play();
		dx = ofRandom(8, 12);
		dy = ofRandom(8, 12);
		bress.play();
	}

	//ボール遊び
	if (mx - x <= 50 && mx - x >= -50 && my - (y - 100) <= 22 && my - (y - 100) >= -22)
	{
		x = 500;
		y = 555;

		x2 = x;
		y2 = y - dogsize * 7.5;
		dy2 = -5;
		bark.play();
	}
	else if (mx - x2 <= dogsize * 1.5 && mx - x2 >= -(dogsize*1.5) && my - y2 <= (dogsize*1.5) && my - y2 >= -(dogsize*1.5))
	{
		x2 = ofGetWidth() - dogsize * 8;
		y2 = ofGetHeight() - dogsize * 1.5;
		dy2 = 0;
	}

	//カラーボール
	if (mx - (x - dogsize * 4.1) <= dogsize / 5 * 4 && mx - (x - dogsize * 4.1) >= -(dogsize / 5 * 4) && my - (y - dogsize * 0.6) <= dogsize / 5 * 4 && my - (dogsize / 5 * 4))
	{
		for (int i = 0; i < 3; i++)
		{
			x3[i] = ofRandom(dogsize*2.5, 100);
			y3[i] = ofRandom(dogsize*2.5, ofGetHeight() - dogsize * 2.5);
			dx3[i] = ofRandom(7, 10);
			dy3[i] = ofRandom(7, 10);
		}
		bark.play();
	}
	else if (mx - (x + dogsize * 4.1) <= dogsize / 5 * 4 && mx - (x + dogsize * 4.1) >= -(dogsize / 5 * 4) && my - (y - dogsize * 0.6) <= dogsize / 5 * 4 && my - (dogsize / 5 * 4))
	{
		for (int i = 0; i < 3; i++)
		{
			x3[i] = dogsize * 4.5;
			y3[i] = ofGetHeight() - dogsize * 2.5;
			dx3[i] = 0;
			dy3[i] = 0;
		}
		toumei[1] = 0;
		toumei[2] = 0;
		toumei[3] = 0;
	}

	//避けるゲーム
	if (mx - x <= dogsize * 0.8 && mx - x >= -(dogsize*0.8) && my - (y + dogsize * 1.3) <= dogsize && my - (y + dogsize * 1.3) >= -dogsize)
	{
		toumei[4] = 255;
		x4[0] = ofGetWidth() / 2;
		y4[0] = dogsize * 15;
		x4[1] = ofGetWidth() / 2;
		y4[1] = dogsize * 30;
		y = ofGetHeight() - dogsize * 4;
		dx4[0] = ofRandom(-5, -4);
		dx4[1] = ofRandom(4, 5);
	}
	//左ボタン
	else if (mx - x5[0] <= dogsize * 1.5 && mx - x5[0] >= -(dogsize*1.5) && my - y5[0] <= dogsize * 3 && my - y5[0] >= -(dogsize * 3))
	{
		bark.play();
		dx = -1;
		dy = -2;
	}
	//右ボタン
	else if (mx - x5[1] <= dogsize * 1.5 && mx - x5[1] >= -(dogsize*1.5) && my - y5[1] <= dogsize * 3 && my - y5[1] >= -(dogsize * 3))
	{
		bark2.play();
		dx = 1;
		dy = -2;
	}
	//下ボタン
	else if (mx - x5[2] <= dogsize * 3 && mx - x5[2] >= -(dogsize * 3) && my - y5[2] <= dogsize * 1.5 && my - y5[2] >= -(dogsize * 1.5))
	{
		bark3.play();
		dx = 0;
		dy = 1;
	}
	//上ボタン
	else if (mx - x5[3] <= dogsize * 3 && mx - x5[3] >= -(dogsize * 3) && my - y5[3] <= dogsize * 1.5 && my - y5[3] >= -(dogsize * 1.5))
	{
		bark4.play();
		dx = 0;
		dy = -1;
	}
	else if (mx - x <= dogsize * 4 && mx - x >= -(dogsize * 4) && my - (y + dogsize * 1.5) <= dogsize * 1.5 && my - (y + dogsize * 1.5) >= -(dogsize*1.5))
	{
		toumei[4] = 0;
		for (int i = 0; i < 2; i++)
		{
			x4[i] = dogsize;
			y4[i] = ofGetHeight() - dogsize;
			dx4[i] = 0;
		}
		dx = 0;
		dy = 0;
		r = 232;
		g = 189;
		b = 134;
	}

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

	toumei[0] = 0;

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
