
with Ada.Text_IO, Ada.Integer_Text_IO, Ada.Numerics.Discrete_Random, Data, System.Multiprocessors;
use Ada.Text_IO, Ada.Integer_Text_IO;

procedure Lab1 is
   subtype Random_Range is Integer range -20..20;
   package Random_Integer is new Ada.Numerics.Discrete_Random(Random_Range);
   use Random_Integer;
   G : Random_Integer.Generator;
   N : Integer;
begin


   Reset(G);
   New_Line;
   Put("Input N - demension of vedctors end matrixes");
   New_Line;
   Get(N);
   declare
      function Get_Rand_Value(V : in Integer) return Integer is
      begin
         return Random(G);
      end;

      function Get_Value(V : in Integer) return Integer is
         Answer : Integer;
      begin
         Get(Answer);
         return Answer;
      end;


      package Data_N_Integer is new Data(N         => N,
                                         T         => Integer,
                                         Zero_Value => 0,
                                         To_String => Integer'Image,
                                         Get_Rand_Value => Get_Rand_Value,
                                         Get_Value => Get_Value);

      use Data_N_Integer;


      -- Func1 --
      d : Integer;
      A, B, C : vector;
      MA, ME : Matrix;

      -- Func2 --
      k : Integer;
      MF, MG, ML : Matrix;

      -- Func3 --
      S, R, T : Vector;
      MO, MP : Matrix;

      Input_Format : Character;

   begin
      New_Line;
      Put("r - Random Input, k - keyboard input");
      New_Line;
      Get(Input_Format);
      if (Input_Format = 'r') then
         --Func1--
         Vector_Input_Rand(V => A);
         Vector_Input_Rand(V => B);
         Vector_Input_Rand(V => C);
         Matrix_Input_Rand(M => MA);
         Matrix_Input_Rand(M => ME);

         --Func2--
         Matrix_Input_Rand(M => MF);
         Matrix_Input_Rand(M => MG);
         Matrix_Input_Rand(M => ML);

         --Func3--
         Vector_Input_Rand(V => R);
         Vector_Input_Rand(V => T);
         Matrix_Input_Rand(M => MO);
         Matrix_Input_Rand(M => MP);

      else
         --Func1--

         Put_Line("Func1 - d = MAX(B + C) + MIN(A + B*(MA*ME))");

         Put_Line("Input Vector A");
         Vector_Input(V => A);
         Put_Line("Input Vector B");
         Vector_Input(V => B);
         Put_Line("Input Vector C");
         Vector_Input(V => C);
         Put_Line("Input Matrix MA");
         Matrix_Input(M => MA);
         Put_Line("Input Matrix ME");
         Matrix_Input(M => ME);

         --Func2--
         Put_Line("Func2 - k = MAX(MF + MG*ML)");
         Put_Line("Input Matrix MF");
         Matrix_Input(M => MF);
         Put_Line("Input Matrix MG");
         Matrix_Input(M => MG);
         Put_Line("Input Matrix ML");
         Matrix_Input(M => ML);

         --Func3--
         Put_Line("Func3 - S = (MO*MP)*(R + T)");
         Put_Line("Input Vector R");
         Vector_Input(V => R);
         Put_Line("Input Vector T");
         Vector_Input(V => T);
         Put_Line("Input Matrix MO");
         Matrix_Input(M => MO);
         Put_Line("Input Matrix MP");
         Matrix_Input(M => MP);
      end if;







      declare
         task Task_Func1 is
            pragma CPU(1);
            pragma Priority(1);
            pragma Storage_Size(1);
         end Task_Func1;



         task body Task_Func1 is
         begin
            Put_Line("Task_Func1 start");

            delay 3.0;
            Func1(A  => A,
                  B  => B,
                  C  => C,
                  MA => MA,
                  ME => ME,
                  d  => d);
            Put_Line("Result of Task_Func1:");
            Put_Line(d'Image);
            Put_Line("Task_Func1 end");
         end Task_Func1;

         task Task_Func2 is
            pragma CPU(2);
            Pragma Priority(2);
         end Task_Func2;

         task body Task_Func2 is
         begin
            Put_Line("Task_Func2 start");
            Func2(MF => MF,
                  MG => MG,
                  ML => ML,
                  k  => k);
            delay 0.0;

            Put_Line("Result of Task_Func2:");
            Put_Line(k'Image);
            Put_Line("Task_Func2 end");
         end Task_Func2;

         task Task_Func3 is
            pragma CPU(3);
            Pragma Priority(10);
         end Task_Func3;

         task body Task_Func3 is
         begin
            Put_Line("Task_Func3 start");

            delay 0.0;
            Func3(R  => R,
                  T  => T,
                  MO => MO,
                  MP => MP,
                  S  => S);
            Put_Line("Result of Task_Func3:");
            Vector_Output(S);
            Put_Line("Task_Func3 end");

         end Task_Func3;

      begin
         null;
      end;

      null;
   end;








end Lab1;



