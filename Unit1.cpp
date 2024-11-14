//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

enum Direction { UP, DOWN, LEFT, RIGHT };
Direction currentDirection = RIGHT;
const int gridSize = 30;
const int headRadius = 15;
const int newSegmentRadius = 16;
const int eyePosition = headRadius / 3;


class TCircle : public TShape {
public:
	TCircle(TComponent* Owner) : TShape(Owner) {
		Parent = Form1->FieldPanel;
		Shape = stCircle;
		Brush->Color = clCream;
	}

	void SetRadius(int radius){
		Width = radius*2;
		Height = radius*2;
	}
};

class TSnake {
private:
	TCircle* head;
	TCircle* leftEye;
	TCircle* rightEye;
	TList* body;
	Direction direction;
	int energy;         // Energy variable
	int movesRemaining; // Number of moves remaining before consuming a segment
	int turnsRemaining; // Number of turns remaining before consuming a segment

	void Move();
	void CheckCollision();
	void Grow();
	void RemoveTailSegment();
	void GameOver();
	void labelling();

public:
	TSnake(TForm* form);
	~TSnake();
	void SetDirection(Direction dir);
	friend void update(TSnake* Snake);
};

TSnake::TSnake(TForm* form) {
	head = new TCircle(form);
	head->Brush->Color = clMoneyGreen;;
	head->SetRadius(headRadius);
	head->Left = rand() % (Form1->FieldPanel->Width - 150) + 50;
	head->Top = rand() % (Form1->FieldPanel->Height - 150) + 50;

	// create and position the left eye circle
	leftEye = new TCircle(form);
	leftEye->Brush->Color = clWhite;
	leftEye->SetRadius(5);
	leftEye->Left = head->Left + 10;
	leftEye->Top = head->Top + 10;

	// create and position the right eye circle
	rightEye = new TCircle(form);
	rightEye->Brush->Color = clWhite;
	rightEye->SetRadius(5);
	rightEye->Left = head->Left + 20;
	rightEye->Top = head->Top + 10;

	// add the head and eye circles to the body list
	body = new TList();
	body->Add(leftEye);
	energy = body->Count;
	body->Add(rightEye);
	body->Add(head);

	direction = RIGHT;
   // Initialize energy based on the number of segments
	movesRemaining = 100;    // Number of moves before consuming a segment
	turnsRemaining = 5;      // Number of turns before consuming a segment
}

TSnake::~TSnake() {
	for (int i = 0; i < body->Count; i++) {
		delete (TCircle*)body->Items[i];
	}
	delete body;
}

void TSnake::labelling(){
	Form1->movesLabel->Caption = IntToStr(movesRemaining);
	Form1->turnsLabel->Caption = IntToStr(turnsRemaining);
	Form1->energyLabel->Caption = IntToStr(energy);
}

void TSnake::SetDirection(Direction dir) {

	if (dir != direction) {
		turnsRemaining -= 1; // Reduce turns remaining by 1 when changing direction
		if (turnsRemaining <= 0) {
			turnsRemaining = 5; // Reset turns remaining
			energy -= 1;        // Reduce energy by 1 when consuming a segment
			if (energy <= 0) {
				// Handle out of energy condition (e.g., game over, reset the snake, etc.)
				// ...
				GameOver();
			}
			else {
				RemoveTailSegment(); // Remove the last segment from the snake's body
			}
		}
	}
	//movesRemaining = 100; // Reset moves remaining when changing direction
	direction = dir;
	currentDirection = dir;
	labelling();
}

void TSnake::Move() {
	int dx = 0, dy = 0, leftEyel = 0, leftEyet = 0, rightEyel = 0, rightEyet = 0;
	switch(direction)
	{
		case UP:
			dy = -gridSize;
			leftEyel = eyePosition;
			leftEyet = headRadius;
			rightEyel = headRadius;
			rightEyet = headRadius;
			break;
		case DOWN:
			dy = gridSize;
			leftEyel = eyePosition;
			leftEyet = eyePosition;
			rightEyel = headRadius;
			rightEyet = eyePosition;
			break;
		case LEFT:
			dx = -gridSize;
			leftEyel = headRadius;
			leftEyet = eyePosition;
			rightEyel = headRadius;
			rightEyet = headRadius;
			break;
		case RIGHT:
			dx = gridSize;
			leftEyel = eyePosition;
			leftEyet = eyePosition;
			rightEyel = eyePosition;
			rightEyet = headRadius;
			break;
	}
	for (int i = body->Count - 1; i > 2; i--) {
		TCircle* segment = (TCircle*)body->Items[i];
		TCircle* prevSegment = (TCircle*)body->Items[i - 1];
		segment->Left = prevSegment->Left;
		segment->Top = prevSegment->Top;
	}
	head->Left += dx;
	head->Top += dy;

	leftEye->Left = head->Left + leftEyel;
	leftEye->Top = head->Top + leftEyet;
	rightEye->Left = head->Left + rightEyel;
	rightEye->Top = head->Top + rightEyet;

	movesRemaining -= 1; // Reduce moves remaining by 1 when moving
	if (movesRemaining <= 0) {
		movesRemaining = 100; // Reset moves remaining
		energy -= 1;          // Reduce energy by 1 when consuming a segment
		if (energy <= 0) {
			// Handle out of energy condition (e.g., game over, reset the snake, etc.)
			// ...
			GameOver();
		}
		else {
			RemoveTailSegment(); // Remove the last segment from the snake's body
		}
	}
	labelling();
}

void TSnake::CheckCollision() {
	if (
		head->Left <= 5 || head->Top <= 5 ||
		head->Left >= (Form1->FieldPanel->Width - 50) ||
		head->Top >= (Form1->FieldPanel->Height - 50)
	)
	{
		GameOver();
	}

	for (int i = 3; i < body->Count; i++)
	{
		TCircle* segment = (TCircle*)body->Items[i];
		if (head->Left == segment->Left && head->Top == segment->Top)
		{
			GameOver();
		}
	}
}

void TSnake::Grow() {
	TCircle* tail = (TCircle*)body->Items[body->Count - 1];
	TCircle* newSegment = new TCircle(tail->Owner);
	newSegment->SetRadius(newSegmentRadius);
	newSegment->Left = tail->Left;
	newSegment->Top = tail->Top;
	body->Add(newSegment);
	Form1->ScoreLabel->Caption = IntToStr(StrToInt(Form1->ScoreLabel->Caption) + 1);
	energy ++;
}

void TSnake::RemoveTailSegment() {
	if (body->Count > 0) {
		TCircle* tailSegment = static_cast<TCircle*>(body->Items[body->Count - 1]);
		body->Remove(tailSegment);
		delete tailSegment;
	}
}

void TSnake::GameOver(){
	Form1->Timer1->Enabled = false;
	ShowMessage("Game Over!");
	Form1->SpeedButton1->Caption = "Start";
	Form1->SpeedButton1->Width = 80;
	currentDirection = RIGHT;
}

void update(TSnake *Snake) {
	Snake->Move();
	Snake->CheckCollision();
	TCircle* head = (TCircle*)(Snake->body->Items[2]);
	if (
		(head->Left >= (Form1->Food->Left) - (head->Width)
		 && head->Left <= Form1->Food->Left + Form1->Food->Width
		 && head->Top >= Form1->Food->Top - head->Height
		 && head->Top <= Form1->Food->Top + Form1->Food->Height)
	) {
		Snake->Grow();
		Form1->Food->Left = rand() % (Form1->FieldPanel->Width - 50) + 5;
		Form1->Food->Top = rand() % (Form1->FieldPanel->Height - 50) + 5;
	}
	Snake->labelling();
}
TSnake *Snake;


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    update(Snake);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{

	switch (Key)
	{
		case VK_UP:
			if (currentDirection != DOWN)
				Snake->SetDirection(UP);
			break;

		case VK_DOWN:
			if (currentDirection != UP)
				Snake->SetDirection(DOWN);
			break;

		case VK_RIGHT:
			if (currentDirection != LEFT)
				Snake->SetDirection(RIGHT);
			break;

		case VK_LEFT:
			if (currentDirection != RIGHT)
				Snake->SetDirection(LEFT);
			break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
	if(Timer1->Enabled){
		Timer1->Enabled = false;
		SpeedButton1->Caption = "Continue";
		SpeedButton1->Width = 150;
	} else if(SpeedButton1->Caption == "Continue"){
		Timer1->Enabled = true;
		SpeedButton1->Caption = "Pause";
		SpeedButton1->Width = 100;
	} else {
		delete Snake;
		Snake = new TSnake(Form1);
		Timer1->Enabled = true;
		SpeedButton1->Caption = "Pause";
		SpeedButton1->Width = 100;
		Food->Visible = true;
		ScoreLabel->Caption = "0";
	}
}
//---------------------------------------------------------------------------


