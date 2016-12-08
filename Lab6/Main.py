from SquareMatrix import SquareMatrix
from Vector import Vector
from MatrixVectorIO import MatrixVectorIO
from multiprocessing import Process
 
size = 300

val = 5


# Func1
# d = MAX(B + C) + MIN(A + B * (MA*ME))
def task1():
  print('Task1 started')
  A = Vector(size)
  B = Vector(size)
  C = Vector(size)
  MA = SquareMatrix(size)
  ME = SquareMatrix(size)
  io = MatrixVectorIO()

  io.vectorInput(A, val)
  io.vectorInput(B, val)
  io.vectorInput(C, val)
  io.matrixInput(MA, val)
  io.matrixInput(ME, val)
  d = B.plusVector(C).max() + A.plusVector(B.multMatrix(MA.multMatrix(ME))).min()
  print('Task1 finished')

# Func2
# k = MAX(MF + MG*ML)
def task2():
  print('Task2 started')
  MF = SquareMatrix(size)
  MG = SquareMatrix(size)
  ML = SquareMatrix(size)
  io = MatrixVectorIO()
  io.matrixInput(MF, val)
  io.matrixInput(MG, val)
  io.matrixInput(ML, val)

  k = MF.plusMatrix(MG.multMatrix(ML)).max()
  print('Task2 finished')

# Func3
# S = (MO * MP) * (R + T)
def task3():
  print('Task3 started')
  R = Vector(size)
  T = Vector(size) 
  MO = SquareMatrix(size)
  MP = SquareMatrix(size)
  io = MatrixVectorIO()
  io.vectorInput(R, val)
  io.vectorInput(T, val)
  io.matrixInput(MO, val)
  io.matrixInput(MP, val)
  S = MO.multMatrix(MP).multVector(R.plusVector(T))
  print('Task3 finished')

if __name__ == '__main__':
  p1 = Process(target=task1)
  p2 = Process(target=task2)
  p3 = Process(target=task3)
  p1.start()
  p2.start()
  p3.start()
  p1.join()
  p2.join()
  p3.join()