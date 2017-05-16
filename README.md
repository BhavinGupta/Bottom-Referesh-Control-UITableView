# Bottom-Referesh-Control-UITableView
Smooth scrolling bottom refresh control for table view with some objects in array.

Just add some dummy data into array with custom referesh control cell in table view or handle response from web service and
populate the data into the array with smooth animation from table view top with this two methods

Make sure these given below methods are very important to show the cell at the end of the table view with your conditional array objects
so that you can show the load more cell in table view with concerned API call for loading more data to an array.

Please go through the demo once and let me know if any query regarding this demo of bottom referesh control.

These were the methods to focus on while loading more data into cell with load more custom cell in table view as below:

#pragma mark - UITableView Delegate and Data Source Methods
// add one for the "loading" cell
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.objects.count + 1;
}

// if within the range of model, return cell with model object in it, otherwise show "loading" cell.
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    static NSString *cellStandardIdentifier = @"Cell";
    static NSString *cellLoadingIdentifier = @"Loading";
    
    if (indexPath.row < self.objects.count) {
        UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:cellStandardIdentifier forIndexPath:indexPath];
        cell.textLabel.text = self.objects[indexPath.row];
        return cell;
    } else {
        LoadingTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:cellLoadingIdentifier forIndexPath:indexPath];
        [cell.activityIndicatorView startAnimating];
        [self fetchMoreData];
        return cell;
    }
}

#pragma mark - Data Fetching
/** Fetch more data. Simulate network request fetching more data. When done, it will reload the tableview.**/
- (void)fetchMoreData {
    static BOOL fetchInProgress = FALSE;
    
    if (fetchInProgress)
        return;
    
    typeof(self) __weak weakSelf = self;
    
    fetchInProgress = TRUE;
    
    // this simulates a background fetch; I'm just going to delay for a second
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1.0 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        typeof(self) strongSelf = weakSelf;
        if (strongSelf) {
            NSArray *indexPaths = [strongSelf addSomeObjects];
            [strongSelf.tableView beginUpdates];
            [strongSelf.tableView insertRowsAtIndexPaths:indexPaths withRowAnimation:UITableViewRowAnimationTop];
            fetchInProgress = FALSE;
            [strongSelf.tableView endUpdates];
        }
    });
}

#pragma mark -  Add Some Dummy Objects To An Array
/** Add some objects to our model. This simulates the retrieval of 20 more items from our data source. This adds the objects to our model returns an array of `NSIndexPath objects that we can use to refresh our table view. @return An array of `NSIndexPath` objects.**/
- (NSArray *)addSomeObjects {
    NSNumberFormatter *formatter = [[NSNumberFormatter alloc] init];
    formatter.numberStyle = NSNumberFormatterSpellOutStyle;
    NSMutableArray *indexPaths = [NSMutableArray array];
    for (NSInteger i = 0; i < 20; i++) {
        [self.objects addObject:[formatter stringFromNumber:@([self.objects count] + 1)]];
        [indexPaths addObject:[NSIndexPath indexPathForRow:self.objects.count - 1 inSection:0]];
    }
    return indexPaths;
}
