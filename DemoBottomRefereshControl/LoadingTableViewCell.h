//
//  LoadingTableViewCell.h
//  DemoBottomRefereshControl
//
//  Created by Bhavin Gupta on 16/05/17.
//  Copyright © 2017 Easy Pay. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface LoadingTableViewCell : UITableViewCell

/** UITableViewCell subclass for "loading" cell
 
 This is a `UITableViewCell` subclass for the cell that shows the "loading" message.
 The only thing this class is really doing is exposing the `IBOutlet` for the `UIActivityIndicatorView`.
 */

@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *activityIndicatorView;

@end
