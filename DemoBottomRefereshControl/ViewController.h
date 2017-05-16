//
//  ViewController.h
//  DemoBottomRefereshControl
//
//  Created by Bhavin Gupta on 16/05/17.
//  Copyright © 2017 Easy Pay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LoadingTableViewCell.h"

@interface ViewController : UIViewController<UITableViewDelegate,UITableViewDataSource>

@property (nonatomic, strong) IBOutlet UITableView *tableView;
@property (nonatomic, strong) NSMutableArray *objects;

@end

