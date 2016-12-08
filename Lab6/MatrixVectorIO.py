from Vector import Vector
from SquareMatrix import SquareMatrix

class MatrixVectorIO:

  def vectorInput(self, vector, val):
    for i in range(vector.getSize()):
      vector.set(i, val)

  def matrixInput(self, matrix, val):
    for i in range(matrix.getSize()):
      for j in range(matrix.getSize()):
        matrix.set(i, j, val)

  def vectorOutput(self, vector):
    print(vector.vector)

  def matrixOutput(self, matrix):
    for i in range(matrix.getSize()):
      print(matrix.matrix[i])