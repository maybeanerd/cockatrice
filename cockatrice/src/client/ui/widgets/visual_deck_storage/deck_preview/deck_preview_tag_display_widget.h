#ifndef DECK_PREVIEW_TAG_DISPLAY_WIDGET_H
#define DECK_PREVIEW_TAG_DISPLAY_WIDGET_H

#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QWidget>

class DeckPreviewTagDisplayWidget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for DeckPreviewTagDisplayWidget.
     * @param parent The parent widget.
     * @param tagName The name of the tag to display.
     */
    explicit DeckPreviewTagDisplayWidget(QWidget *parent = nullptr, const QString &tagName = "");
    QSize sizeHint() const override;
    QString getTagName() const
    {
        return tagName;
    }
    bool getSelected() const
    {
        return isSelected;
    }

    /**
     * @brief Sets the selected state of the tag.
     * @param selected True if the tag is selected, false otherwise.
     */
    void setSelected(bool selected);

signals:
    /**
     * @brief Emitted when the tag is clicked.
     */
    void tagClicked();

    /**
     * @brief Emitted when the close button is clicked.
     */
    void tagClosed();

protected:
    /**
     * @brief Custom paint event for drawing the widget.
     * @param event The paint event.
     */
    void paintEvent(QPaintEvent *event) override;

    /**
     * @brief Custom mouse press event handler.
     * @param event The mouse event.
     */
    void mousePressEvent(QMouseEvent *event) override;

private:
    QLabel *tagLabel;         ///< Label for displaying the tag name.
    QPushButton *closeButton; ///< Button to close/remove the tag.
    QString tagName;          ///< The name of the tag.
    bool isSelected;          ///< Indicates whether the tag is selected.
};

#endif // DECK_PREVIEW_TAG_DISPLAY_WIDGET_H
