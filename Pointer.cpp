#include <vcl.h>
#include <string.h>
#include "Pointer.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
	DoubleBuffered = true;
	bitmap1 = new Graphics::TBitmap;
	bitmap1->Width = Image1->Width;
	bitmap1->Height = Image1->Height;

	rect1.left = 0;
	rect1.top = 0;
	rect1.right = Image1->Width;
	rect1.bottom = Image1->Height;

	Draw_Shield();
}
// ---------------------------------------------------------------------------

class TSamplePointer {
public:
	int angle;
	int value;
	int target;
	int max_value;
	int shield;
	bool out_of_range;
	bool run;
	TColor color1;
	TColor color2;

	TSamplePointer()
		: angle(-100), value(0), target(0), max_value(200),
		shield(45), out_of_range(false), run(false), color1(RGB(200, 200, 200)),
		color2(RGB(130, 130, 130)) {
	}

	void Set_Color(TColor c1, TColor c2) {
		color1 = c1;
		color2 = c2;
	}
};

/* class TDiode {
 *public:
 *	bool enabled;
 *	TColor color;
 *
 *	TDiode() {
 *		enabled = false;
 *		color = clGray;
 *	}
 * };
 */

TSamplePointer pointer1; // create object called pointer1
// TDiode diode1;

// ---------------------------------------------------------------------------

void TForm1::Draw_Shield() {
int size = Image1->Width;
int center_pos = (size / 2);

bitmap1->Canvas->Brush->Color = clBtnShadow;
bitmap1->Canvas->Pen->Color = clBlack;
bitmap1->Canvas->Pen->Width = 0;
bitmap1->Canvas->Rectangle(0, 0, size, size);
bitmap1->Canvas->Brush->Color = clBlack;
bitmap1->Canvas->Pen->Color = clBlack;
bitmap1->Canvas->Pen->Width = 0;
bitmap1->Canvas->Ellipse(5, 5, 10, 10); // sruby xD
bitmap1->Canvas->Ellipse(size - 5, size - 5, size - 10, size - 10);
bitmap1->Canvas->Ellipse(size - 5, 5, size - 10, 10);
bitmap1->Canvas->Ellipse(5, size - 5, 10, size - 10);

bitmap1->Canvas->Pen->Width = 0;
bitmap1->Canvas->Brush->Color = RGB(56, 56, 56);
bitmap1->Canvas->Ellipse(2, 2, size - 2, size - 2); // circle outside

for (int i = 6; i < 60; i++) { // shield inside
	TColor color1 = RGB(0, 70 + i + pointer1.shield - 6,
		111 + i + pointer1.shield - 6);
	bitmap1->Canvas->Pen->Color = color1;
	bitmap1->Canvas->Brush->Color = color1;
	bitmap1->Canvas->Ellipse(i, i, size - i, size - i);
}

/* //+++++++++diode+++++++++++
 *
 *	for (int i = 0; i < 20; i++) { // center point
 *		TColor color1 = RGB(i*2, i*2, i*2);
 *		bitmap1->Canvas->Pen->Color = color1;
 *		bitmap1->Canvas->Brush->Color = color1;
 *		bitmap1->Canvas->Ellipse(i + size/2, i + size - size/4, -i+size/2, -i + size - size/4);
 *	}
 */

bitmap1->Canvas->Brush->Color = RGB(104, 104, 104);

bitmap1->Canvas->Pen->Width = 2;
bitmap1->Canvas->Pen->Color = clBlack;

SetBkMode(bitmap1->Canvas->Handle, TRANSPARENT);

bitmap1->Canvas->Font->Size = 14;
bitmap1->Canvas->Font->Name = "Arial";
bitmap1->Canvas->Font->Color = clBlack;
bitmap1->Canvas->TextOut(center_pos - (IntToStr(pointer1.value).Length() + 3)
	/ 2 * 12, 180, IntToStr(pointer1.value) + "µm");

// pointer angle
pointer1.angle = -120 + ((240.0 / pointer1.max_value) * pointer1.value);

bitmap1->Canvas->Pen->Width = 0;
int a = 12;
int counter = 0;
int max_step = 20;

TPoint p[5]; // scale

for (int i = -50; i <= 50; i++) {
	static int counter = 0;
	p[0] = TPoint(center_pos + 130 * Cos(((i * a / 5.00) + 270) * 3.14 / 180.0),
		center_pos + 130 * Sin(((i * a / 5.00) + 270) * 3.14 / 180.0));
	p[1] = TPoint(center_pos + 140 * Cos(((i * a / 5.00) + 270) * 3.14 / 180.0),
		center_pos + 140 * Sin(((i * a / 5.00) + 270) * 3.14 / 180.0));

	bitmap1->Canvas->Pen->Color = clBlack;
	bitmap1->Canvas->Brush->Color = RGB(55, 55, 55);
	bitmap1->Canvas->Polygon(p, 1);
	counter++;
}

for (int i = -10; i <= 10; i++) {
	p[0] = TPoint(center_pos + 120 * Cos(((i * a) + 270) * 3.14 / 180),
		center_pos + 120 * Sin(((i * a) + 270) * 3.14 / 180));
	p[1] = TPoint(center_pos + 140 * Cos(((i * a) + 270 - 1) * 3.14 / 180),
		center_pos + 140 * Sin(((i * a) + 270 - 1) * 3.14 / 180));
	p[2] = TPoint(center_pos + 140 * Cos(((i * a) + 270 + 1) * 3.14 / 180),
		center_pos + 140 * Sin(((i * a) + 270 + 1) * 3.14 / 180));

	bitmap1->Canvas->Pen->Color = clBlack;
	bitmap1->Canvas->Brush->Color =
		RGB((255 / 20) * counter, 255 - (255 / 20) * counter, 0);
	bitmap1->Canvas->Polygon(p, 2);

	bitmap1->Canvas->Font->Size = 10;
	bitmap1->Canvas->Font->Name = "Comic Sans MS";
	bitmap1->Canvas->Font->Color = clBlack;

	SetBkMode(bitmap1->Canvas->Handle, TRANSPARENT);
	// remove text bckground
	bitmap1->Canvas->TextOut
		(center_pos + 105 * Cos(((i * a) + 270) * 3.14 / 180) +
		15 * Cos(225 * 3.14 / 180),
		center_pos + 105 * Sin(((i * a) + 270) * 3.14 / 180) +
		15 * Sin(225 * 3.14 / 180),
		IntToStr(pointer1.max_value*counter / max_step));
	counter++;
}

// 1 side pointer - left
bitmap1->Canvas->Pen->Width = 1;
p[0] = TPoint(center_pos, center_pos);
p[1] = TPoint(center_pos + 20 * Cos((pointer1.angle + 240) * 3.14 / 180),
	center_pos + 20 * Sin((pointer1.angle + 240) * 3.14 / 180));
p[2] = TPoint(center_pos + 135 * Cos((pointer1.angle + 270) * 3.14 / 180),
	center_pos + 135 * Sin((pointer1.angle + 270) * 3.14 / 180));
bitmap1->Canvas->Pen->Color = clBlack;
bitmap1->Canvas->Brush->Color = pointer1.color1;
bitmap1->Canvas->Polygon(p, 2);

// 2 side of pointer - right
p[0] = TPoint(center_pos, center_pos);
p[1] = TPoint(center_pos + 135 * Cos((pointer1.angle + 270) * 3.14 / 180),
	center_pos + 135 * Sin((pointer1.angle + 270) * 3.14 / 180));
p[2] = TPoint(center_pos + 20 * Cos((pointer1.angle + 300) * 3.14 / 180),
	center_pos + 20 * Sin((pointer1.angle + 300) * 3.14 / 180));
bitmap1->Canvas->Pen->Color = clBlack;
bitmap1->Canvas->Brush->Color = pointer1.color2;
bitmap1->Canvas->Polygon(p, 2);

for (int i = (-size / (10 * 5)) + (size / 2);
i < (size / (10 * 5)) + (size / 2); i++) { // center point
	bitmap1->Canvas->Pen->Color = clBlack;
	bitmap1->Canvas->Brush->Color = pointer1.color2;
	bitmap1->Canvas->Ellipse(i, i, size - i, size - i);
}

if (pointer1.out_of_range) {
	bitmap1->Canvas->Font->Size = 16;
	bitmap1->Canvas->Font->Name = "Courier New";
	bitmap1->Canvas->Brush->Color = RGB(0, 125, 200);
	bitmap1->Canvas->Font->Color = RGB(255, 0, 0);
	bitmap1->Canvas->TextOut(size / 2 - 7 * 12, size - size / 4,
		"OUT OF RANGE!");

}

Image1->Canvas->CopyRect(rect1, bitmap1->Canvas, rect1);
}

// ---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender) {
if (pointer1.run) {
	if (pointer1.value < pointer1.target && pointer1.value < pointer1.max_value)
	{
		pointer1.value += 1;
	}

	pointer1.out_of_range = pointer1.target > pointer1.max_value;

	if (pointer1.target >
		pointer1.max_value && pointer1.value == pointer1.max_value)
		pointer1.target = pointer1.max_value;

	if (pointer1.value > pointer1.target)
		if (pointer1.value > 0)
			pointer1.value -= 1;

	if (pointer1.value > pointer1.max_value)
		pointer1.value = pointer1.max_value;

	Draw_Shield();
}
if (pointer1.value == pointer1.target) {
	pointer1.run = false;
}

GroupBox2->Enabled = !pointer1.run;
}

// ---------------------------------------------------------------------------

void __fastcall TForm1::SetButtonClick(TObject *Sender) {
if (StrToInt(EditValue->Text) >= 0) {
	pointer1.target = StrToInt(EditValue->Text);
	pointer1.run = true;
}
else {
	EditValue->Text = "0";
}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action) {
delete bitmap1;
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::TrackBar1Change(TObject *Sender) {
switch (TrackBar1->Position) {
case 0:
	pointer1.Set_Color(RGB(200, 200, 200), RGB(130, 130, 130)); // gray
	break;
case 1:
	pointer1.Set_Color(RGB(255, 0, 0), RGB(180, 0, 0)); // red
	break;
case 2:
	pointer1.Set_Color(RGB(0, 255, 0), RGB(0, 180, 0)); // green
	break;
case 3:
	pointer1.Set_Color(RGB(0, 0, 255), RGB(0, 0, 180)); // blue
	break;
case 4:
	pointer1.Set_Color(RGB(255, 255, 0), RGB(180, 180, 0)); // yellow
	break;
case 5:
	pointer1.Set_Color(RGB(255, 0, 255), RGB(189, 0, 151)); // pink
	break;
}
Draw_Shield();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::ScrollBar1Change(TObject *Sender) {
pointer1.shield = ScrollBar1->Position;
Draw_Shield();
}
// ---------------------------------------------------------------------------
