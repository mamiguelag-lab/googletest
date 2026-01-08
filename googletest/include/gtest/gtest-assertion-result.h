::AssertionFailure() << n << " is odd";
//   () 
  }

 private:
  // Appends the contents of message to message_.
  void AppendMessage(const Message& a_message) {
    if (message_ == nullptr) message_ = ::std::make_unique<::std::string>();
    message_->append(a_message.GetString().c_str());
  }

  // Swap the contents of this AssertionResult with other.
  void swap(AssertionResult& other);

  // Stores result of the assertion predicate.
  bool success_;
  // Stores the message describing the condition in case the expectation
  // construct is not satisfied with the predicate's outcome.
  // Referenced via a pointer to avoid taking too much stack frame space
  // with test assertions.
  std::unique_ptr< ::std::string> message_;
};

// Makes a successful assertion result.
GTEST_API_ 