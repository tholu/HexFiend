/* A document used for file diffing */

#import "BaseDataDocument.h"

@class DiffOverlayView, DiffTextViewContainer;

@interface DiffDocument : BaseDataDocument {
    HFByteArray *leftBytes, *rightBytes;
    HFByteArrayEditScript *editScript;
    IBOutlet HFTextView *leftTextView;
    IBOutlet HFTextView *rightTextView;
    IBOutlet NSTableView *diffTable;
    IBOutlet DiffTextViewContainer *textViewContainer;
    DiffOverlayView *overlayView;
    NSUInteger focusedInstructionIndex;
    NSString *title;
    BOOL synchronizingControllers;
    
    HFDocumentOperationView *diffComputationView;
    
    // abstract scroll space support
    IBOutlet NSScroller *scroller;
    unsigned long long totalAbstractLength;
    long double currentScrollPosition;
    
    // momentum scroll hackery
    BOOL handledLastScrollEvent;
    CFAbsoluteTime timeOfLastScrollEvent;
    
    HFRange range_;
}

+ (NSArray *)getFrontTwoDocumentsForDiffing;
+ (void)compareDocument:(BaseDataDocument *)document againstDocument:(BaseDataDocument *)otherDocument usingRange:(HFRange)range;
+ (void)compareFrontTwoDocuments;
+ (void)compareFrontTwoDocumentsUsingRange:(HFRange)range;

- (instancetype)initWithLeftByteArray:(HFByteArray *)left rightByteArray:(HFByteArray *)right;
- (instancetype)initWithLeftByteArray:(HFByteArray *)left rightByteArray:(HFByteArray *)right range:(HFRange)range;
- (BOOL)handleEvent:(NSEvent *)event;

@property (nonatomic, copy) NSString *leftFileName;
@property (nonatomic, copy) NSString *rightFileName;

- (IBAction)scrollerDidChangeValue:(NSScroller *)scroller;

@end
