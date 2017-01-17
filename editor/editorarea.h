#include <QWidget>
#include <QShortcut>
#include <QPainter>
#include <QTimer>
#include <QScrollArea>
#include <QMessageBox>
#include <QColor>
#include <QMouseEvent>
#include <QBitmap>

#include "mediator.h"

#ifndef EDITORTILEPALLETE
    #include "editortilepallete.h"
#endif

#ifndef FILE_GAME
	#include "../file/format.h"
#endif

extern int palleteX;
extern int palleteY;

struct pointElement{
   int palleteX, palleteY, type;
};

class EditorArea : public QWidget
{
  Q_OBJECT

public:
  // methods
  EditorArea(QWidget *parent = 0);

  // variables
  QWidget *myParent;

  void update_files();

private:

  // variables
  int link_pos_x;
  int link_pos_y;
  int link_map_origin;
  int link_size;


protected:
  // methods
  void paintEvent(QPaintEvent *event);
  void mousePressEvent(QMouseEvent * event);
  void mouseReleaseEvent(QMouseEvent * event);
  void mouseMoveEvent(QMouseEvent *event);

  // variables
  int temp;
  int editor_selectedTileX, editor_selectedTileY;
  int tempX, tempY;
  int editor_selected_object_pos;
  int editor_selected_object_pos_map;
  void fill_area();

  int map_backup_n;
  bool mouse_released;
  bool selection_started;

  int selection_start_x;
  int selection_start_y;
  std::vector<std::vector<st_position> > selection_matrix;
  int selection_current_x;
  int selection_current_y;

  QPixmap hard_mode_tile;
  QPixmap easy_mode_tile;
  QPixmap tileset_image;
  QBitmap tileset_bitmap;
  QPixmap bg1_image;
  QPixmap fg_layer__image;
  float fg_opacity;




//signals:
//     void save();

public slots:
   void changeTile();

};
