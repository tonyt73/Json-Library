object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 360
  ClientWidth = 471
  Color = clBtnFace
  Constraints.MinHeight = 399
  Constraints.MinWidth = 487
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnActivate = FormActivate
  OnCreate = FormCreate
  DesignSize = (
    471
    360)
  TextHeight = 15
  object Label1: TLabel
    Left = 16
    Top = 19
    Width = 31
    Height = 15
    Caption = 'String'
  end
  object Label2: TLabel
    Left = 16
    Top = 48
    Width = 37
    Height = 15
    Caption = 'Integer'
  end
  object Label3: TLabel
    Left = 16
    Top = 78
    Width = 26
    Height = 15
    Caption = 'Float'
  end
  object Label4: TLabel
    Left = 16
    Top = 129
    Width = 36
    Height = 15
    Caption = 'People'
  end
  object Label5: TLabel
    Left = 16
    Top = 243
    Width = 57
    Height = 15
    Caption = 'First Name'
  end
  object Label6: TLabel
    Left = 17
    Top = 272
    Width = 56
    Height = 15
    Caption = 'Last Name'
  end
  object Label7: TLabel
    Left = 17
    Top = 301
    Width = 21
    Height = 15
    Caption = 'Age'
  end
  object Edit1: TEdit
    Left = 104
    Top = 16
    Width = 121
    Height = 23
    TabOrder = 0
    Text = 'Edit1'
    OnChange = OnChange
  end
  object SpinEdit1: TSpinEdit
    Left = 104
    Top = 45
    Width = 121
    Height = 24
    MaxValue = 0
    MinValue = 0
    TabOrder = 1
    Value = 100
    OnChange = OnChange
  end
  object Edit2: TEdit
    Left = 104
    Top = 75
    Width = 121
    Height = 23
    TabOrder = 2
    Text = '123.456'
    OnChange = OnChange
  end
  object CheckBox1: TCheckBox
    Left = 13
    Top = 104
    Width = 108
    Height = 17
    Alignment = taLeftJustify
    Caption = 'Boolean'
    TabOrder = 3
    OnClick = OnChange
  end
  object ListBox1: TListBox
    Left = 104
    Top = 129
    Width = 121
    Height = 97
    ItemHeight = 15
    TabOrder = 4
  end
  object Edit3: TEdit
    Left = 104
    Top = 240
    Width = 121
    Height = 23
    TabOrder = 5
    Text = 'John'
  end
  object Edit4: TEdit
    Left = 104
    Top = 269
    Width = 121
    Height = 23
    TabOrder = 6
    Text = 'Smith'
  end
  object SpinEdit2: TSpinEdit
    Left = 104
    Top = 298
    Width = 121
    Height = 24
    MaxValue = 0
    MinValue = 0
    TabOrder = 7
    Value = 56
  end
  object Button1: TButton
    Left = 150
    Top = 328
    Width = 75
    Height = 25
    Caption = 'Add Person'
    TabOrder = 8
    OnClick = Button1Click
  end
  object Memo1: TMemo
    Left = 241
    Top = 16
    Width = 222
    Height = 337
    Anchors = [akLeft, akTop, akRight, akBottom]
    Constraints.MinHeight = 336
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Consolas'
    Font.Style = []
    Lines.Strings = (
      'Memo1')
    ParentFont = False
    ScrollBars = ssBoth
    TabOrder = 9
  end
end
