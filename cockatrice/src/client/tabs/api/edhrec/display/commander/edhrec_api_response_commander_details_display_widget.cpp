#include "edhrec_api_response_commander_details_display_widget.h"

#include "../../../../../../game/cards/card_database_manager.h"
#include "../../../../../ui/widgets/cards/card_info_picture_widget.h"
#include "../card_prices/edhrec_api_response_card_prices_display_widget.h"

EdhrecCommanderResponseCommanderDetailsDisplayWidget::EdhrecCommanderResponseCommanderDetailsDisplayWidget(
    QWidget *parent,
    const EdhrecCommanderApiResponseCommanderDetails &_commanderDetails,
    QString baseUrl)
    : QWidget(parent), commanderDetails(_commanderDetails)
{
    layout = new QVBoxLayout(this);
    setLayout(layout);

    commanderPicture = new CardInfoPictureWidget(this);
    commanderPicture->setCard(CardDatabaseManager::getInstance()->getCard(commanderDetails.getName()));

    commanderDetails.debugPrint();

    label = new QLabel(this);
    label->setAlignment(Qt::AlignCenter);
    salt = new QLabel(this);
    salt->setAlignment(Qt::AlignCenter);

    cardPricesDisplayWidget = new EdhrecApiResponseCardPricesDisplayWidget(this, commanderDetails.getPrices());

    navigationWidget = new EdhrecCommanderApiResponseNavigationWidget(this, commanderDetails, baseUrl);

    layout->addWidget(commanderPicture);
    layout->addWidget(label);
    layout->addWidget(salt);
    layout->addWidget(cardPricesDisplayWidget);
    layout->addWidget(navigationWidget);

    retranslateUi();
}

void EdhrecCommanderResponseCommanderDetailsDisplayWidget::retranslateUi()
{
    label->setText(commanderDetails.getLabel());
    salt->setText(tr("Salt: ") + QString::number(commanderDetails.getSalt()));
}
