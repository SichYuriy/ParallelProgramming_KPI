with Ada.Text_IO;
use Ada.Text_IO;

package body Data is


   procedure Vector_Input_Rand(V : out Vector) is
   begin
      for I in Size_N loop
         V(I) := Get_Rand_Value(0);
      end loop;
   end Vector_Input_Rand;

   procedure Vector_Input(V : out Vector) is
   begin

      for I in Size_N loop
         V(I) := Get_Value(0);
      end loop;

   end;


   procedure Matrix_Input_Rand(M : out Matrix) is
   begin
      for I in Size_N loop
         for J in Size_N loop
            M(I)(J) := Get_Rand_Value(0);
         end loop;
      end loop;
   end Matrix_Input_Rand;

   procedure Matrix_Input(M : out Matrix) is
   begin

      for I in Size_N loop
         for J in Size_N loop
            M(I)(J) := Get_Value(0);
         end loop;
      end loop;

   end;


   procedure Vector_Output(V : in Vector) is
   begin
      New_Line;
      for I in Size_N loop

         Output_String(To_String(V(I)), 6);

      end loop;
      New_Line;
   end Vector_Output;

   procedure Matrix_Output(M : in Matrix) is
   begin
      New_Line;
      for I in Size_N loop
         for J in Size_N loop
            Output_String(To_String(M(I)(J)), 6);

         end loop;
         New_Line;
      end loop;
      New_Line;
   end Matrix_Output;


   procedure Output_String(Item : in String;
                           Width : in Integer) is

   begin
      if Item'Length < Width then
         for I in 1 .. Width - Item'Length loop
            Put(" ");
         end loop;

      end if;
      Put(Item);
   end Output_String;






   function "+"(A, B : in Vector) return Vector;

   function "+"(MA, MB : in Matrix) return Matrix;

   function "*"(MA, MB : in Matrix) return Matrix;

   function "*"(V : in Vector; MA : in Matrix) return Vector;

   function "*"(MA : in Matrix; V : in Vector) return Vector;

   function Max(V : in Vector) return T;

   function Min(V : in Vector) return T;

   function Max(MA : in Matrix) return T;

   --TODO--

   function "*"(a : in T; V : in Vector) return Vector;

   function "*"(a : in T; MA: in Matrix) return Matrix;

   function "*"(A, B : in Vector) return T;

   function Sort(V : in Vector) return Vector;

   function Trans(MA : in Matrix) return Matrix;

   function Min(MA : in Matrix) return T;

   function Sort(MA : in Matrix) return Matrix;





   function "+"(A, B : in Vector) return Vector is
      Answer : Vector;
   begin
      for I in 1..A'Length loop
         Answer(I) := A(I) + B(I);
      end loop;
      return Answer;
   end "+";

   function "+"(MA, MB : in Matrix) return Matrix is
      Answer : Matrix;
   begin
      for I in Size_N loop
         for J in Size_N loop
            Answer(I)(J) := MA(I)(J) + MB(I)(J);
         end loop;
      end loop;
      return Answer;
   end "+";


   function Max(V : in Vector) return T is
      Answer : T;
   begin
      Answer := V(1);
      for I In 2..V'Length loop
         if Answer < V(I) then
            Answer := V(I);
         end if;
      end loop;
      return Answer;
   end Max;

   function Min(V : in Vector) return T is
      Answer : T;
   begin
      Answer := V(1);
      for I In 2..V'Length loop
         if V(I) < Answer then
            Answer := V(I);
         end if;
      end loop;
      return Answer;
   end Min;

   function Max(MA : in Matrix) return T is
      Answer : T;
   begin
      Answer := MA(1)(1);
      for I in Size_N loop
         for J in Size_N loop
            if Answer < MA(I)(J) then
               Answer := MA(I)(J);
            end if;
         end loop;
      end loop;
      return Answer;

   end Max;


   function "*"(MA, MB : in Matrix) return Matrix is
      Answer : Matrix;
   begin
      for I in Size_N loop
         for J in Size_n loop
            Answer(I)(J) := Zero_Value;
            for K in Size_N loop
               Answer(I)(J) := Answer(I)(J) + MA(I)(K) * MB(K)(J);
            end loop;
         end loop;
      end loop;
      return Answer;

   end "*";

   function "*"(V : in Vector; MA : in Matrix) return Vector is
      Answer : Vector;
   begin
      for I in Size_N loop
         Answer(I) := Zero_Value;
         for J in Size_N loop
            Answer(I) := Answer(I) + V(I) * MA(J)(I);
         end loop;
      end loop;
      return Answer;

   end "*";

   function "*"(MA : in Matrix; V : in Vector) return Vector is
   begin
      return V * MA;
   end "*";

   function "*"(a : in T; V : in Vector) return Vector is
      Answer : Vector;
   begin
      for I in Size_N loop
         Answer(I) := a * V(I);
      end loop;
      return Answer;
   end "*";


   function "*"(a : in T; MA: in Matrix) return Matrix is
      Answer : Matrix;
   begin
      for I in Size_N loop
         for J in Size_N loop
            Answer(I)(J) := a * MA(I)(J);
         end loop;
      end loop;
      return Answer;
   end "*";

   function "*"(A, B : in Vector) return T is
      Answer : T;
   begin
      Answer := Zero_Value;
      for I in Size_N loop
         Answer := Answer + A(I) * B(I);
      end loop;
      return Answer;
   end "*";

   function Sort(V : in Vector) return Vector is
      Answer : Vector;
      p : T;
   begin
      for I in Size_N loop
         Answer(I) := V(I);
      end loop;
      for I in 2..V'Length loop
         for J in I..2 loop
            if Answer(J) < Answer(J - 1) then
               p := Answer(J);
               Answer(J) := Answer(J - 1);
               Answer(J - 1) := p;
            end if;
         end loop;
      end loop;
      return Answer;
   end Sort;

   function Trans(MA : in Matrix) return Matrix is
      Answer : Matrix;
   begin
      for I in Size_N loop
         for J in Size_N loop
            Answer(I)(J) := MA(Size_N'Last - I + 1)(Size_N'Last - J - 1);
         end loop;
      end loop;
      return Answer;

   end Trans;

   function Sort(MA : in Matrix) return Matrix is
      Answer : Matrix;
   begin
      for I in Size_N loop
         Answer(I) := Sort(MA(I));
      end loop;
      return Answer;
   end Sort;

   function Min(MA : in Matrix) return T is
      Answer : T;
      V : Vector;
   begin
      for I in Size_N loop
         V(I) := Min(MA(I));
      end loop;
      Answer := Min(V);
      return Answer;
   end Min;





   procedure Func1(A, B, C : in Vector; MA, ME : in Matrix; d : out T) is
   begin
      d := Max(B + C) + MIN(A + B * (MA * ME));
   end Func1;

   procedure Func2(MF, MG, ML : in Matrix; k : out T) is
   begin
      k := Max(MF + MG * ML);

   end Func2;


   procedure Func3(R, T : in Vector; MO, MP : in Matrix; S : out Vector) is
   begin
      S := (MO * MP)*(R + T);
   end Func3;









end Data;
