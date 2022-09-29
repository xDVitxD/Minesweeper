#pragma once
#include <random>

int WinColor[3] = {50, 255, 50}; //RGB
int LossColor[3] = {255, 50, 50}; //RGB
int Offset[2] = {0, 0}; //X,Y
int SizeOfTile[2] = {30, 30}; //X.Y
int SizeOfField[2] = {9, 9}; //X,Y
int SizeOfOpenedBorderTile = 1;
int SizeOfClosedBorderTile = 2;
int TileOpenedBorder[3] = {15, 15, 15}; //RGB
int TileClosedBorder[3] = {75, 75,75}; //RGB
int TileOpened[3] = {100, 100, 100}; //RGB
int TileClosed[3] = {35, 35, 35}; //RGB
int TileOpenedBomb[3] = {255, 50, 50}; //RGB
int NumberOfBombs = 10;
int TotalOpenedTiles = 0;
int CurrentFieldData[9999] = {};
int CurrentFieldBombs[9999] = {};
int CurrentFieldFlags[9999] = {};
int OpenedTiles[9999] = {};
int Color_Index[][3] = {
	{128, 128, 255},
	{0, 255, 0},
	{255, 0, 0},
	{0, 0, 128},
	{0, 0, 128},
	{0, 128, 128},
	{0, 0, 0},
	{255, 255, 255}
};
//Indexes
int Index_0 = 0;
int Index_1 = 1;
int Index_2 = 2;
int Index_3 = 3;
int Index_4 = 4;
int Index_5 = 5;
int Index_6 = 6;
int Index_7 = 7;
int Index_8 = 8;
int Index_Bomb = 9;
int Index_Flag = 10;
int Index_Question = 11;

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		cli::array<Button^> ^Buttons = gcnew cli::array<Button^, 1>(9999);



		   cli::array<Label^>^ TileLabels = gcnew cli::array<Label^, 1>(9999);
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ EndGameLabel;
	private: System::Windows::Forms::Button^ RestartGame;
	private: System::Windows::Forms::Label^ Tiles;




	protected:

	protected:


	protected:



	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->EndGameLabel = (gcnew System::Windows::Forms::Label());
			this->RestartGame = (gcnew System::Windows::Forms::Button());
			this->Tiles = (gcnew System::Windows::Forms::Label());
			this->EndGameLabel->SuspendLayout();
			this->SuspendLayout();
			// 
			// EndGameLabel
			// 
			this->EndGameLabel->BackColor = System::Drawing::Color::Transparent;
			this->EndGameLabel->Controls->Add(this->RestartGame);
			resources->ApplyResources(this->EndGameLabel, L"EndGameLabel");
			this->EndGameLabel->Name = L"EndGameLabel";
			// 
			// RestartGame
			// 
			this->RestartGame->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(75)),
				static_cast<System::Int32>(static_cast<System::Byte>(75)));
			this->RestartGame->FlatAppearance->BorderSize = 0;
			resources->ApplyResources(this->RestartGame, L"RestartGame");
			this->RestartGame->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->RestartGame->Name = L"RestartGame";
			this->RestartGame->UseVisualStyleBackColor = false;
			this->RestartGame->Click += gcnew System::EventHandler(this, &MyForm::RestartGameFunction);
			// 
			// Tiles
			// 
			this->Tiles->BackColor = System::Drawing::Color::Transparent;
			resources->ApplyResources(this->Tiles, L"Tiles");
			this->Tiles->Name = L"Tiles";
			// 
			// MyForm
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->Controls->Add(this->EndGameLabel);
			this->Controls->Add(this->Tiles);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			this->EndGameLabel->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	template < class T, class U >
	Boolean isinst(U u) {
		return dynamic_cast<T>(u) != nullptr;
	}
	private: System::Void UpdateField() {
		UpdateFieldData();
		this->SuspendLayout();
		for (int Position = 0; Position < SizeOfField[0] * SizeOfField[1]; Position++) {
			System::Windows::Forms::Button^ Tile = Buttons[Position];
			System::Windows::Forms::Label^ TileLabel = TileLabels[Position];
			Tile->BackColor = System::Drawing::Color::FromArgb(255, TileClosed[0], TileClosed[1], TileClosed[2]);
			Tile->FlatAppearance->MouseOverBackColor = Tile->BackColor;
			Tile->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Empty;
			Tile->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			TileLabel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			TileLabel->Text = "";
			TileLabel->Visible = false;
			UpdateButtonBorder(Tile, TileClosedBorder, SizeOfClosedBorderTile);
		}
		this->ResumeLayout(false);
	}
	private: System::Void UpdateFieldData() {
		int i = 0;
		int CreatedBombs = 0;
		TotalOpenedTiles = 0;
		std::fill_n(CurrentFieldData, SizeOfField[0] * SizeOfField[1], NULL);
		std::fill_n(CurrentFieldBombs, SizeOfField[0] * SizeOfField[1], NULL);
		std::fill_n(CurrentFieldFlags, SizeOfField[0] * SizeOfField[1], NULL);
		std::fill_n(OpenedTiles, SizeOfField[0] * SizeOfField[1], NULL);
		while (CreatedBombs < NumberOfBombs) {
			std::random_device rd;   // non-deterministic generator
			std::mt19937 gen(rd());
			std::uniform_int_distribution<> RandomRange(0, SizeOfField[0] * SizeOfField[1]);
			int RandomNumber = RandomRange(gen);
			if (CurrentFieldData[RandomNumber] == Index_0 || CurrentFieldData[RandomNumber] == NULL) {
				CurrentFieldData[RandomNumber] = Index_Bomb;
				CurrentFieldBombs[RandomNumber] = Index_Bomb;
				CreatedBombs++;
			}
		}
	}
	private: System::Void CreateField() {
		System::Drawing::Font^ TileFont = gcnew System::Drawing::Font("Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold);
		for (int X = 0; X < SizeOfField[0]; X++) {
			for (int Y = 0; Y < SizeOfField[1]; Y++) {
				System::Windows::Forms::Button^ Tile = gcnew System::Windows::Forms::Button();
				System::Windows::Forms::Label^ TileLabel = gcnew System::Windows::Forms::Label();
				int TileName = (X * SizeOfField[1]) + Y;
				Tile->AllowDrop = false;
				Tile->BackColor = System::Drawing::Color::FromArgb(255, TileClosed[0], TileClosed[1], TileClosed[2]);
				Tile->FlatAppearance->MouseOverBackColor = Tile->BackColor;
				Tile->FlatAppearance->BorderSize = 0;
				Tile->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				Tile->Location = System::Drawing::Point(Offset[0]+(X * SizeOfTile[0]), Offset[1] + (Y * SizeOfTile[1]));
				Tile->Name = TileName.ToString();
				Tile->Size = System::Drawing::Size(SizeOfTile[0], SizeOfTile[1]);
				Tile->TabIndex = 0;
				Tile->UseVisualStyleBackColor = false;
				Tile->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::HandleTileMouseClick);
				Tile->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(0, 0, 0, 0);
				Tile->Controls->Add(TileLabel);
				this->Tiles->Controls->Add(Tile);
				System::Windows::Forms::Label^ LeftRightTop = gcnew System::Windows::Forms::Label();
				System::Windows::Forms::Label^ UpDownRight = gcnew System::Windows::Forms::Label();
				System::Windows::Forms::Label^ LeftRightBottom = gcnew System::Windows::Forms::Label();
				System::Windows::Forms::Label^ UpDownLeft = gcnew System::Windows::Forms::Label();
				LeftRightTop->Name = L"LeftRightTop";
				UpDownRight->Name = L"UpDownRight";
				LeftRightBottom->Name = L"LeftRightBottom";
				UpDownLeft->Name = L"UpDownLeft";
				Tile->Controls->Add(UpDownRight);
				Tile->Controls->Add(LeftRightBottom);
				Tile->Controls->Add(LeftRightTop);
				Tile->Controls->Add(UpDownLeft);
				UpdateButtonBorder(Tile,TileClosedBorder,SizeOfClosedBorderTile);
				Buttons[TileName] = Tile;
				
				TileLabel->AutoSize = false;
				TileLabel->Font = TileFont;
				TileLabel->Name = TileName.ToString();
				TileLabel->Size = System::Drawing::Size(SizeOfTile[0]-6, SizeOfTile[1]-6);
				TileLabel->Location = System::Drawing::Point(3, 3);
				TileLabel->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this,&MyForm::HandleTileMouseClick);
				TileLabel->BackColor = System::Drawing::Color::Transparent;
				TileLabel->Visible = false;
				TileLabels[TileName] = TileLabel;
			}
		}
	}
	private: System::Void HandleTileMouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		int Index;
		if (isinst< System::Windows::Forms::Label^ >(sender)) {
			Index = Int32::Parse(((System::Windows::Forms::Label^)sender)->Name);
		}else if (isinst< System::Windows::Forms::Button^ >(sender)) {
			Index = Int32::Parse(((System::Windows::Forms::Button^)sender)->Name);
		}
		System::Drawing::Point Location = Buttons[Index]->Location;
		System::Drawing::Point Position = System::Drawing::Point(Location.X + e->X, Location.Y + e->Y);
		if (Position.X >= 0 && Position.X <= this->ClientSize.Width && Position.Y >= 0 && Position.Y <= this->ClientSize.Height) {
			System::Object^ NewSender = Buttons[((Position.X / SizeOfTile[0]) * SizeOfField[1]) + Position.Y / SizeOfTile[1]];
			if (e->Button == System::Windows::Forms::MouseButtons::Left) {
				Tile_Pressed(NewSender, System::EventArgs::Empty);
			}else if (e->Button == System::Windows::Forms::MouseButtons::Right) {
				Tile_Mark(NewSender, System::EventArgs::Empty);
			}
		}
	}
	private: System::Void RestartGameFunction(System::Object^ sender, System::EventArgs^ e) {
		this->EndGameLabel->Visible = false;
		UpdateField();
	}
	private: System::Void EndGame(System::String^ Text,int Color[3]) {
		this->EndGameLabel->Visible = true;
		this->RestartGame->Visible = true;
		this->EndGameLabel->AutoSize = false;
		this->EndGameLabel->TextAlign = System::Drawing::ContentAlignment::TopCenter;
		this->EndGameLabel->Text = "\n"+Text;
		this->EndGameLabel->ForeColor = System::Drawing::Color::FromArgb(255, Color[0], Color[1], Color[2]);
		this->EndGameLabel->Location = System::Drawing::Point(0, (this->ClientSize.Height / 2) - SizeOfTile[1]*1.5);
		this->EndGameLabel->Size = System::Drawing::Size(this->ClientSize.Width,SizeOfTile[1] * 3);
		this->RestartGame->Location = System::Drawing::Point((this->ClientSize.Width / 2) - (SizeOfTile[0] * 2), EndGameLabel->Size.Height/2);
		this->RestartGame->Size = System::Drawing::Size((SizeOfTile[0] * 4), SizeOfTile[1]);
	}
	private: System::Void ShowAllBombs(System::Windows::Forms::Button ^PressedTile) {
		for (int Position = 0; Position < SizeOfField[0] * SizeOfField[1]; Position++) {
			System::Windows::Forms::Button^ Tile = Buttons[Position];
			System::Windows::Forms::Label^ TileLabel = TileLabels[Position];
			Tile->FlatAppearance->MouseOverBackColor = Tile->BackColor;
			Tile->FlatAppearance->MouseDownBackColor = Tile->BackColor;
			if (CurrentFieldBombs[Position] == Index_Bomb) {
				TileLabel->Text = "◉";
				TileLabel->ForeColor = System::Drawing::Color::FromArgb(255, 255, 255, 255);
				TileLabel->Visible = true;
			}
		}
		PressedTile->BackColor = System::Drawing::Color::FromArgb(255, TileOpenedBomb[0], TileOpenedBomb[1], TileOpenedBomb[2]);
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		MyForm_Resize(sender, e);
		CreateField();
		UpdateFieldData();
	}
	private: System::Void MyForm_Resize(System::Object^ sender, System::EventArgs^ e) {
		this->ClientSize = System::Drawing::Size(Offset[0] + (SizeOfField[0] * (SizeOfTile[0] + 1)) - SizeOfField[0], Offset[1] + (SizeOfField[1] * (SizeOfTile[1] + 1)) - SizeOfField[1]);
	}
	private: void OpenTile(int Position) {
		System::Windows::Forms::Button^ Tile = Buttons[Position];
		System::Windows::Forms::Label^ TileLabel = TileLabels[Position];
		int BombsClose = 0;
		int X = Position / SizeOfField[1];
		int Y = Position % SizeOfField[1];
		if (CurrentFieldData[Position] == Index_Bomb) {
			ShowAllBombs(Tile);
			EndGame("Поражение!", LossColor);
		}else if (OpenedTiles[Position] == NULL || !OpenedTiles[Position]) {
			TotalOpenedTiles++;
			OpenedTiles[Position] = true;
			cli::array<int, 2>^ Tiles = gcnew cli::array<int, 2>(8, 2) {
				{X - 1, Y - 1},
				{ X,Y - 1 },
				{ X + 1,Y - 1 },
				{ X + 1,Y },
				{ X + 1,Y + 1 },
				{ X,Y + 1 },
				{ X - 1,Y + 1 },
				{ X - 1,Y }
			};
			for (int Index = 0; Index < sizeof(Tiles); Index++) {
				int X = Tiles[Index, 0];
				int Y = Tiles[Index, 1];
				if (X >= 0 && X < SizeOfField[0] && Y >= 0 && Y < SizeOfField[1]) {
					if (CurrentFieldData[X * SizeOfField[1] + Y] == Index_Bomb) {
						BombsClose++;
					}
				}
			}
			Tile->BackColor = System::Drawing::Color::FromArgb(255, TileOpened[0], TileOpened[1], TileOpened[2]);
			if (BombsClose > 0) {
				TileLabel->Text = BombsClose.ToString();
				TileLabel->ForeColor = System::Drawing::Color::FromArgb(255, Color_Index[BombsClose - 1][0], Color_Index[BombsClose - 1][1], Color_Index[BombsClose - 1][2]);
			}else {
				for (int Index = 0; Index < sizeof(Tiles); Index++) {
					int X = Tiles[Index, 0];
					int Y = Tiles[Index, 1];
					if (X >= 0 && X < SizeOfField[0] && Y >= 0 && Y < SizeOfField[1]) {
						OpenTile(X * SizeOfField[1] + Y);
					}
				}
			};
			Tile->FlatAppearance->MouseOverBackColor = Tile->BackColor;
			Tile->FlatAppearance->MouseDownBackColor = Tile->BackColor;
			UpdateButtonBorder(Tile, TileOpenedBorder, SizeOfOpenedBorderTile);
			TileLabel->Visible = true;
			if (TotalOpenedTiles >= (SizeOfField[0] * SizeOfField[1])-NumberOfBombs) {
				EndGame("Победа!", WinColor);
			}
		}
	}
	private: System::Void Tile_Pressed(System::Object^ sender, System::EventArgs^ e) {
		if (!EndGameLabel->Visible) {
			int Position;
			if (isinst< System::Windows::Forms::Label^ >(sender)) {
				Position = Int32::Parse(((System::Windows::Forms::Label^)sender)->Name);
			}else if (isinst< System::Windows::Forms::Button^ >(sender)) {
				Position = Int32::Parse(((System::Windows::Forms::Button^)sender)->Name);
			}
			OpenTile(Position);
		}
	}
	private: System::Void Tile_Mark(System::Object^ sender, System::EventArgs^ e) {
		if (!EndGameLabel->Visible) {
			int Position;
			if (isinst< System::Windows::Forms::Label^ >(sender)) {
				Position = Int32::Parse(((System::Windows::Forms::Label^)sender)->Name);
			}else if (isinst< System::Windows::Forms::Button^ >(sender)) {
				Position = Int32::Parse(((System::Windows::Forms::Button^)sender)->Name);
			}
			if (OpenedTiles[Position] == NULL || !OpenedTiles[Position]) {
				System::Windows::Forms::Label^ TileLabel = TileLabels[Position];
				if (CurrentFieldFlags[Position] == NULL) {
					CurrentFieldFlags[Position] = Index_Flag;
					TileLabel->Text = "⚑";
					TileLabel->ForeColor = System::Drawing::Color::FromArgb(255, 255, 255, 255);
				}else if (CurrentFieldFlags[Position] == Index_Flag) {
					CurrentFieldFlags[Position] = Index_Question;
					TileLabel->Text = "?";
					TileLabel->ForeColor = System::Drawing::Color::FromArgb(255, 255, 255, 255);
				}else if (CurrentFieldFlags[Position] == Index_Question) {
					CurrentFieldFlags[Position] = NULL;
				}
				TileLabel->Visible = CurrentFieldFlags[Position] == Index_Flag || CurrentFieldFlags[Position] == Index_Question;
			}
		}
	}
	private: System::Void UpdateButtonBorder(System::Windows::Forms::Button^ Button, int Color[3],int SizeOfBorderTile) {
		System::Windows::Forms::Label ^LeftRightTop, ^UpDownRight, ^LeftRightBottom, ^UpDownLeft;
		for each (System::Windows::Forms::Label ^ BorderLine in Button->Controls) {
			if (BorderLine->Name == "LeftRightTop") {
				LeftRightTop = BorderLine;
			} else if (BorderLine->Name == "UpDownRight") {
				UpDownRight = BorderLine;
			}else if (BorderLine->Name == "LeftRightBottom") {
				LeftRightBottom = BorderLine;
			}else if (BorderLine->Name == "UpDownLeft") {
				UpDownLeft = BorderLine;
			}
		}
		LeftRightTop->Location = Drawing::Point(0, 0);
		UpDownRight->Location = Drawing::Point(SizeOfTile[0] - SizeOfBorderTile, 0);
		LeftRightBottom->Location = Drawing::Point(0, SizeOfTile[1] - SizeOfBorderTile);
		UpDownLeft->Location = Drawing::Point(0, 0);
		LeftRightTop->Size = Drawing::Size(SizeOfTile[0], SizeOfBorderTile);
		UpDownRight->Size = Drawing::Size(SizeOfBorderTile, SizeOfTile[1]);
		LeftRightBottom->Size = Drawing::Size(SizeOfTile[0], SizeOfBorderTile);
		UpDownLeft->Size = Drawing::Size(SizeOfBorderTile, SizeOfTile[1]);
		LeftRightTop->BackColor = System::Drawing::Color::FromArgb(255, Color[0] * 2, Color[1] * 2, Color[2] * 2);
		UpDownRight->BackColor = System::Drawing::Color::FromArgb(255, Color[0], Color[1], Color[2]);
		LeftRightBottom->BackColor = System::Drawing::Color::FromArgb(255, Color[0], Color[1], Color[2]);
		UpDownLeft->BackColor = System::Drawing::Color::FromArgb(255, Color[0] * 2, Color[1] * 2, Color[2] * 2);
	}
};
}