generic

   N : in Natural;

   type T is private;
   Zero_Value : in T;
   with function Get_Rand_Value(Value : in Integer) return T;
   with function Get_Value(Value : in Integer) return T;
   with function To_String(Value : in T) return String;
   with function "*"(X, Y: in T) return T is <>;
   with function "<"(X, Y: in T) return Boolean is <>;
   with function "+"(X, Y: in T) return T is <>;



package Data is
   type Vector is private;
   type Matrix is private;

   procedure Func1(A, B, C : in Vector; MA, ME : in Matrix; d : out T);

   procedure Func2(MF, MG, ML : in Matrix; k : out T);

   procedure Func3(R, T : in Vector; MO, MP : in Matrix; S : out Vector);

   procedure Vector_Input_Rand(V : out Vector);

   procedure Matrix_Input_Rand(M : out Matrix);

   procedure Vector_Input(V : out Vector);

   procedure Matrix_Input(M : out Matrix);

   procedure Vector_Output(V : in Vector);

   procedure Matrix_Output(M : in Matrix);

   procedure Output_String(Item : in String;
                          Width : in Integer);

private

   subtype Size_N is Positive range 1..N;
   type Vector is Array (Size_N) of T;
   type Matrix is Array (Size_N) of Vector;

end Data;
