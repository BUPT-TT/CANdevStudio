#ifndef UNIQUEFILTERMODEL_H
#define UNIQUEFILTERMODEL_H

#include <QSortFilterProxyModel>

/**
*   @brief This class provides a filter model between source model and table view, which passes through only frames with
*          newest unique ID and direction values
*/
class UniqueFilterModel : public QSortFilterProxyModel {
    Q_OBJECT
public:
    explicit UniqueFilterModel(QObject* parent = 0);

    /**
    *   @brief  Updates filter with unique values, on reception of each frame
    *   @param  frameID current frame ID
    *   @param  time elapsed time since simulation start
    *   @param  direction TX or RX
    */
    void updateFilter(int frameID, double time, QString direction);

    /**
    *   @brief  Clears unique values stored in filter
    */
    void clearFilter();

    /**
    *   @brief  Indicates whether filter is currently active
    *   @return true if active, false if inactive
    */
    bool isFilterActive();

protected:
    /**
    *   @brief  Function iterates whole data model row by row and indicates, if currently processed row should be
    *           displayed in table view or not
    *   @param  source_row currently processed model row index
    *   @param  source_parent QModelIndex pointing at source data model
    *   @return true if row is accepted by filter, false if not
    */
    bool filterAcceptsRow(int source_row, const QModelIndex& source_parent) const override;

signals:

public slots:
    /**
    *   @brief  Function toggles filter on/off
    */
    void toggleFilter();

private:
    QMap<QPair<int, QString>, double> uniques;
    bool filterActive = false;
};
#endif
