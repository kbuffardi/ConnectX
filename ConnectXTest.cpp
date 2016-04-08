/**
 * Unit Tests for ConnectX class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "ConnectX.h"

static const Piece mINVALID = -1;
static const Piece mEMPTY = 0;
static const Piece mWHITE = 1;
static const Piece mBLACK = 2;

class ConnectXTest : public ::testing::Test
{
	protected:
		ConnectXTest(){}
		virtual ~ConnectXTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};


TEST(ConnectXTest, checkIfAllEmpty)
{
  ConnectX connectX;
  int i, j;

  for(i=0; i<DEFAULT_HEIGHT; i++){
    for(j=0; j<DEFAULT_WIDTH; j++){
      ASSERT_EQ(mEMPTY, connectX.at(j, i));
    }
  }

}

TEST(ConnectXTest, accessingElementWhichIsOutOfBoard)
{
  ConnectX connectX;

  int i;

	/**
	 * Accessing elements on right column of board
	 */
  for(i=0; i<=DEFAULT_HEIGHT; i++){

    ASSERT_EQ(mINVALID, connectX.at(DEFAULT_WIDTH, i));
  }

  for(i=0; i<DEFAULT_WIDTH; i++){

    ASSERT_EQ(mINVALID, connectX.at(i, DEFAULT_HEIGHT));
  }

  /**
   *  at() fails to return INVALID when given out of bound indexes.
	 *	The issue is in inBounds() function. It returns TRUE even if WIDTH is
	 *	more than DEFAULT_WIDTH but height is in range of DEFAULT_HEIGHT.
  **/


}

TEST(ConnectXTest, at_FunctionReturnsCorrectElement)
{
  ConnectX connectX;

  connectX.placePiece(0);

  ASSERT_EQ(mBLACK, connectX.at(0, DEFAULT_HEIGHT-1));
}

TEST(ConnectXTest, completeBoardIsAccessible)
{
  ConnectX connectX;
  int i, j, flip=0; //0 for Black, 1 for WHITE

  for(i=0; i<DEFAULT_HEIGHT; i++){
    for(j=0; j<DEFAULT_WIDTH; j++){
      connectX.placePiece(j);
    }
  }

  for(i=DEFAULT_HEIGHT-1; i>=0; i--){
    for(j=0; j<DEFAULT_WIDTH; j++){

      if(flip == 0){
        ASSERT_EQ(mBLACK, connectX.at(j, i));
        flip = 1;
      } else {
        ASSERT_EQ(mWHITE, connectX.at(j, i));
        flip = 0;
      }
    }
  }
}

TEST(ConnectXTest, extraPiecesInSingleColumn)
{
  ConnectX connectX;
	int flip = 0, hm1;

	hm1 = DEFAULT_HEIGHT-1;

	int extraHeight = DEFAULT_HEIGHT*2;
	for(int i=0; i<extraHeight; i++){
		connectX.placePiece(0);
	}

	for(int i=hm1; i<=0; i--){
		if(flip == 0){
			ASSERT_EQ(mBLACK, connectX.at(0, hm1));
			flip = 1;
		} else {
			ASSERT_EQ(mWHITE, connectX.at(0, hm1));
			flip = 0;
		}
	}
}

TEST(ConnectXTest, whoseTurnFunctionBehaviour)
{
  ConnectX connectX;
	int flip = 0;


	for(int i=0; i<DEFAULT_WIDTH; i++){
		if(flip == 0){
			ASSERT_EQ(mBLACK, connectX.whoseTurn());
			flip = 1;
		} else {
			ASSERT_EQ(mWHITE, connectX.whoseTurn());
			flip = 0;
		}

		connectX.placePiece(i);
	}

}

TEST(ConnectXTest, constructorWithPositiveValuesCheck)
{
	int width = 200, height = 500, x = 20;
  ConnectX connectX(width, height, x);

	int i, j, flip=0; //0 for Black, 1 for WHITE

	for(i=0; i<height; i++){
    for(j=0; j<width; j++){
      connectX.placePiece(j);
    }
  }

  for(i=height-1; i>=0; i--){
    for(j=0; j<width; j++){

      if(flip == 0){
        ASSERT_EQ(mBLACK, connectX.at(j, i));
        flip = 1;
      } else {
        ASSERT_EQ(mWHITE, connectX.at(j, i));
        flip = 0;
      }
    }
  }

}

/*
 *	Constructor should pick up individual default values.
 *	Explained: If I give height and x positive number but width negative,
 *	constructor should only pick default values of width. And use provided
 *	height and x.
 */
TEST(ConnectXTest, constructorWithOnlyOneNegativeValueCheck)
{
	int width = -50, height = 20, x = 5;
  ConnectX connectX(width, height, x);

	int i, flip=0, hm1; //0 for BLACK, 1 for WHITE

	hm1 = height-1;

	//std::cout<< "  • Placing pieces in first column till full ...";
  for(i=0; i<height; i++){
    connectX.placePiece(0);
  }
	std::cout<< "\b\b\b    DONE" << std::endl;

	//std::cout<< "  • Validating all pieces in first column" <<  std::endl;
	for(i=0; i<height; i++){

		if(flip == 0){
	  	ASSERT_EQ(mBLACK, connectX.at(i, hm1));
	    flip = 1;
	  } else {
	    ASSERT_EQ(mWHITE, connectX.at(i, hm1));
	    flip = 0;
	  }
  }

}

TEST(ConnectXTest, placePieceAtNegativePos)
{
  ConnectX connectX;

	//connectX.placePiece(-1);
	ASSERT_TRUE(0);

}
